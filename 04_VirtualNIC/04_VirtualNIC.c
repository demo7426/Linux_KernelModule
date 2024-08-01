/*************************************************
Copyright (C), 2009-2012    , Level Chip Co., Ltd.
文件名:	04_VirtualNIC.c
作  者:	钱锐      版本: V1.0.0     新建日期: 2024.08.01
描  述: 编写一个简易的虚拟网卡驱动
备  注:	
修改记录:

  1.  日期: 2024.08.01
	  作者: 钱锐
	  内容:
		  1) 此为模板第一个版本；
	  版本:V1.0.0

*************************************************/

#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/netdevice.h>

#define RTn_FAILURE -2                      //失败
#define RTN_SUCCESS 0                       //成功


static struct net_device *g_ptNetDev = NULL;

/// @brief 打开虚拟网卡
/// @param _pDev 
/// @return -2--执行失败;0--执行成功
static int VirtualNIC_Open(struct net_device *_pDev);

/// @brief 停止虚拟网卡
/// @param _pDev 
/// @return -2--执行失败;0--执行成功
static int VirtualNIC_Stop(struct net_device *_pDev);

/// @brief 
/// @param _pSkB 
/// @param _pDev 
/// @return 
static netdev_tx_t VirtualNIC_Start_Xmit(struct sk_buff *_pSkB, struct net_device *_pDev);

/// @brief 设置虚拟网卡的属性
/// @param _pDev 
static void VirtualNIC_SetProperty(struct net_device *_pDev);


static struct net_device_ops tNetDevOps = 
{
    .ndo_open = VirtualNIC_Open,
    .ndo_stop = VirtualNIC_Stop,
    .ndo_start_xmit = VirtualNIC_Start_Xmit,
};

/// @brief 虚拟网卡设备初始化操作
/// @param  
/// @return 
static int __init VirtualNIC_Init(void)
{
    int nRtn = 0;

    g_ptNetDev = alloc_netdev(0, "vnic%d", NET_NAME_UNKNOWN, VirtualNIC_SetProperty);               //分配网络设备
    if (g_ptNetDev == NULL)
    {
        printk(KERN_ERR "VirtualNIC_Init alloc_netdev err.\n");
        return -ENOMEM;
    }
    
    nRtn = register_netdev(g_ptNetDev);                                                             //向内核注册网络设备
    if(nRtn != 0)
    {
        printk(KERN_ERR "VirtualNIC_Init register_netdev err.\n");
        free_netdev(g_ptNetDev);
        return nRtn;
    }

    printk(KERN_INFO "VirtualNIC_Init success.\n");
    return nRtn;
}

static int VirtualNIC_Open(struct net_device *_pDev)
{
    netif_start_queue(_pDev);

    printk(KERN_INFO "VirtualNIC_Open success.\n");
    return RTN_SUCCESS;
}

static int VirtualNIC_Stop(struct net_device *_pDev)
{
    netif_stop_queue(_pDev);

    printk(KERN_INFO "VirtualNIC_Stop success.\n");
    return RTN_SUCCESS;
}

static netdev_tx_t VirtualNIC_Start_Xmit(struct sk_buff *_pSkB, struct net_device *_pDev)
{
    dev_kfree_skb(_pSkB);

    printk(KERN_INFO "VirtualNIC_Start_Xmit success.\n");
    return NETDEV_TX_OK;
}

/// @brief 虚拟网卡设备退出操作
/// @param  
/// @return 
static void __exit VirtualNIC_Exit(void)
{
    unregister_netdev(g_ptNetDev);
    free_netdev(g_ptNetDev);
    printk(KERN_INFO "VirtualNIC_Exit success.\n");
}

void VirtualNIC_SetProperty(struct net_device *_pDev)
{
    //设置网络设备的私有数据和其他属性
    ether_setup(_pDev);
    _pDev->netdev_ops = &tNetDevOps;
}

module_init(VirtualNIC_Init);
module_exit(VirtualNIC_Exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("qianrui");
MODULE_DESCRIPTION("A simple virtual network interface card.");


