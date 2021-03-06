
/**************************** (C) COPYRIGHT 2019 ****************************
* 项目作者: 侍任伟(Tigerots)
* 创建时间: 2019.12.28
* 功能描述: 基于STM32F103xx(HAL库)的bootloader, bootloader使用的是RT-thread-nano
            操作系统,开源免费, 纯系统占用内存约3K
      
* 使用说明: 1. 拷贝my_iap.c/.h, my_flash.c/.h, my_uart.c/.h到项目目录,并添加到工程
            2. 调用iap_thread_init()对iap外设及参数进行初始化(可根据自己需要修改)
            3. 应用程序map根据my_iap.h设置或修改
            4. 应用程序Target/IROM1修改程序start和size(参考my_iap.h)
            5. 应用程序修改宏定义VECT_TAB_OFFSET, 在system_stm32f1xx.c文件中
            6. 通信协议为弗斯特公司所有
            7. 不明之处, 详询作者: 18503259627

* ********************************修改历史记录********************************
* 修改时间: 
* 版本号:
* 修改内容:
*****************************************************************************/

#include "my_iap.h"
#include "rtthread.h"
#include "stm32f1xx_hal.h"

/**********************************函数描述***********************************
* 创建人:   侍任伟
* 创建时间: 2019.12.28
* 功能描述: IAP主函数
            1. 初始化片内外设
            2. 读取升级标志数据结构
            3. 转存用户代码到执行区
            4. 如果升级失败,可直接传输固件(待定)
* 入口参数: 
* 函数返回: 
*****************************************************************************/
int main(void)
{
    //调用iap线程初始化
    iap_thread_init();
    while (1)
    {
        rt_thread_mdelay(100);
    }
}

