

#ifndef  __IAP_H__
#define  __IAP_H__
 

#ifndef  IAP
#define	 __IAPEXT  extern
#else
#define	 __IAPEXT 
#endif


//使用的芯片类型 STM32F103RC
#define USE_STM32F103xC
#ifdef USE_STM32F103xC
    //片内Flash大小:256K
    #define FLASH_SIZE (0x40000)
    //扇区大小:2K
    #define PAGE_SIZE (0x800)
    //默认地址映射
    #define c_BootAddr 0x08000000
    #define c_BootSize 0x8000 //32K
    #define c_UserAddr 0x08008000
    #define c_UserSize 0x19000 //100K
    #define c_BuffAddr 0x08021000
    #define c_BuffSize 0x19000 //100K
    #define c_ParaAddr 0x0803A000
    #define c_ParaSize 0x6000 //24K
#endif
#ifdef USE_STM32F103xD
    //片内Flash大小:256K
    #define FLASH_SIZE (0x40000)
    //扇区大小:2K
    #define PAGE_SIZE (0x800)
    //默认地址映射
    #define c_BootAddr 0x08000000
    #define c_BootSize 0x8000 //32K
    #define c_UserAddr 0x08008000
    #define c_UserSize 0x29000 //164K
    #define c_BuffAddr 0x08031000
    #define c_BuffSize 0x29000 //164K
    #define c_ParaAddr 0x0805A000
    #define c_ParaSize 0x6000 //24K
#endif
#ifdef USE_STM32F103xE
    //片内Flash大小:256K
    #define FLASH_SIZE (0x40000)
    //扇区大小:2K
    #define PAGE_SIZE (0x800)
    //默认地址映射
    #define c_BootAddr 0x08000000
    #define c_BootSize 0x10000 //64K
    #define c_UserAddr 0x08010000
    #define c_UserSize 0x32000 //200K
    #define c_BuffAddr 0x08042000
    #define c_BuffSize 0x32000 //200K
    #define c_ParaAddr 0x08074000
    #define c_ParaSize 0xC000 //48K
#endif



//内存地址映射表
__packed typedef struct
{
    unsigned long BootAddr;//bootloader起始地址
    unsigned long BootSize;//bootloader占用内存大小
    unsigned long UserAddr;//应用程序起始地址
    unsigned long UserSize;//应用程序占用内存大小
    unsigned long BuffAddr;//升级代码缓存起始地址
    unsigned long BuffSize;//升级代码缓存占用内存大小
    unsigned long ParaAddr;//用户参数区起始地址
    unsigned long ParaSize;//应用程序占用内存大小 
}MyIapMapType;
__IAPEXT MyIapMapType MyIapMap;



//升级标志数据结构,存放于ParaAddr第一个扇区,占用一个扇区空间
__packed typedef struct
{
    unsigned long DevType;//适用的设备类型
    unsigned long ChipType;//适用的芯片类型
    unsigned long FileSizeMax;//升级文件最大值
    unsigned long FileSizeMin;//升级文件最小值
    
    unsigned char UpdataFlag;//升级标志 
    //    0:无升级需求 
    //    1:正在缓存升级代码 
    //    2:升级代码缓存完成,重启拷贝 
    //    3:升级完成,重启运行
    //    0x55:升级失败
    //    0xAA:恢复出厂设置
    unsigned char UpdataCnt;//升级次数记录
    unsigned char UpdataType;//升级类型
    //    0: 选择升级
    //    1: 强制升级
    unsigned int SoftFilter;//固件版本过滤, 大于该版本的需要升级
    unsigned int HardFilter;//适应的硬件版本, 大于该版本的需要升级
    
    unsigned char FileType;//文件类型
    //    0: Hex文件(具有行校验,体积较大,ascii方式传输)
    //    1: Bin文件(纯二进制文件,无任何校验,体积小,十六进制传输)
    //    2: Fst文件(具有文件信息,体积较大,ascii方式传输)
    unsigned char CommType;//通信交互方式
    //    0: 广播方式,无应答
    //    1: 问答方式,一问一答
    unsigned char CommGap;//通信包间隔,单位ms
    unsigned int  PackSize;//数据单包大小(4的整数倍)
    
}MyIapFlagType;
__IAPEXT MyIapFlagType MyIapFlag;


#endif







