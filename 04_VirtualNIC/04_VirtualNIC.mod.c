#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(.gnu.linkonce.this_module) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section(__versions) = {
	{ 0xdd8f8694, "module_layout" },
	{ 0x3d7fbf14, "param_ops_charp" },
	{ 0x754f3d58, "unregister_netdev" },
	{ 0x32ec28ed, "free_netdev" },
	{ 0x9e61fe6d, "register_netdev" },
	{ 0xc28f897e, "alloc_netdev_mqs" },
	{ 0xf95117c8, "netif_rx" },
	{ 0x8cc57f6f, "eth_type_trans" },
	{ 0x69acdf38, "memcpy" },
	{ 0x559069b0, "skb_put" },
	{ 0xa8fc9a46, "__netdev_alloc_skb" },
	{ 0xfc8fdece, "consume_skb" },
	{ 0x9d92fb56, "dev_queue_xmit" },
	{ 0xa3bfbf9e, "dev_get_by_name" },
	{ 0x30cb0399, "init_net" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0x547a10d9, "ether_setup" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "1BC3D73C5A15B5F74EE6BFC");
