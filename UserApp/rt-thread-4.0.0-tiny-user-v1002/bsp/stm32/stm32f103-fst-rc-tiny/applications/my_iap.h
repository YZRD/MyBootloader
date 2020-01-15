

#ifndef  __IAP_H__
#define  __IAP_H__
 

#ifndef  __MY_IAP
#define	 __IAPEXT  extern
#else
#define	 __IAPEXT 
#endif

#include "my_type.h"
#include "rtdef.h"



//LEDָʾ����ʾ״̬
__IAPEXT unsigned char  Led_status;
#define Led_status MyIapLedStatus 


//ʹ�õ�оƬ���� STM32F103RC
#define USE_STM32F103xC
#ifdef USE_STM32F103xC
    //Flash����ַ
    #define STM_FLASH_BASE (0x08000000)
    //Ƭ��Flash��С:256K
    #define STM_FLASH_SIZE (0x40000)
    //������С:2K
    #define STM_PAGE_SIZE (0x800)
    //Ĭ�ϵ�ַӳ��
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
    //Flash����ַ
    #define STM_FLASH_BASE (0x08000000)
    //Ƭ��Flash��С:384K
    #define STM_FLASH_SIZE (0x60000)
    //������С:2K
    #define STM_PAGE_SIZE (0x800)
    //Ĭ�ϵ�ַӳ��
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
    //Flash����ַ
    #define STM_FLASH_BASE (0x08000000)
    //Ƭ��Flash��С:512K
    #define STM_FLASH_SIZE (0x80000)
    //������С:2K
    #define STM_PAGE_SIZE (0x800)
    //Ĭ�ϵ�ַӳ��
    #define c_BootAddr 0x08000000
    #define c_BootSize 0x10000 //64K
    #define c_UserAddr 0x08010000
    #define c_UserSize 0x32000 //200K
    #define c_BuffAddr 0x08042000
    #define c_BuffSize 0x32000 //200K
    #define c_ParaAddr 0x08074000
    #define c_ParaSize 0xC000 //48K
#endif



//�ڴ��ַӳ���
__packed typedef struct
{
    unsigned long BootAddr;//bootloader��ʼ��ַ
    unsigned long BootSize;//bootloaderռ���ڴ��С
    unsigned long UserAddr;//Ӧ�ó�����ʼ��ַ
    unsigned long UserSize;//Ӧ�ó���ռ���ڴ��С
    unsigned long BuffAddr;//�������뻺����ʼ��ַ
    unsigned long BuffSize;//�������뻺��ռ���ڴ��С
    unsigned long ParaAddr;//�û���������ʼ��ַ
    unsigned long ParaSize;//Ӧ�ó���ռ���ڴ��С 
}MyIapMapType;
__IAPEXT MyIapMapType MyIapMap;



//������־���ݽṹ,�����ParaAddr��һ������,ռ��һ�������ռ�
__packed typedef struct
{
    unsigned char IsInitFlag;//�Ƿ��Ѿ���ʼ����־
        
    unsigned long DevType;//���õ��豸����
    unsigned long ChipType;//���õ�оƬ����
    unsigned long FileSize;//�����ļ���С
    unsigned long FileSizeMax;//�����ļ����ֵ
    unsigned long FileSizeMin;//�����ļ���Сֵ
    
    unsigned char UpdataFlag;//������־ 
    //    0:�����������������
    //    1:��Ҫ����,�Ѿ������������� 
    //    2:�������,��������(Ӧ�ó��򽫱�־��0,���ѭ��)
    //    0x55:����ʧ��
    //    0xAA:�ָ���������
    unsigned char UpdataCnt;//����������¼
    unsigned char UpdataType;//��������
    //    0: ѡ������
    //    1: ǿ������
    unsigned int SoftFilter;//�̼��汾����, ���ڸð汾����Ҫ����
    unsigned int HardFilter;//��Ӧ��Ӳ���汾, ���ڸð汾����Ҫ����
    
    unsigned char FileType;//�ļ�����
    //    0: Hex�ļ�(������У��,����ϴ�,ascii��ʽ����)
    //    1: Bin�ļ�(���������ļ�,���κ�У��,���С,ʮ�����ƴ���)
    //    2: Fst�ļ�(�����ļ���Ϣ,����ϴ�,ascii��ʽ����)
    unsigned char CommType;//ͨ�Ž�����ʽ
    //    0: �㲥��ʽ,��Ӧ��
    //    1: �ʴ�ʽ,һ��һ��
    unsigned int CommGap;//ͨ�Ű����,��λms
    unsigned int PackSize;//���ݵ�����С(4��������)
    
}MyIapFlagType;
__IAPEXT MyIapFlagType MyIapFlag;


//����iap��д����
__packed typedef struct
{
    unsigned char WriteFlag;//д��־
    //0:������
    //1:��������,��������
    //2:�������,��������
    //3:�������,дUpdataFlag��־Ϊ1,����
    unsigned char WriteStep;//д����
    //0:����
    //1:�����������
    //2:����д��,��������
    //3:д���
    unsigned long WriteTime;//��һ��д��ʱ��
    unsigned long WriteAddr;//��ǰд��ַ
    unsigned long WriteSize;//��ǰ����С
    unsigned long WriteTatolCnt;//�Ѿ�д���ֽ�
    unsigned char WriteBuff[STM_PAGE_SIZE];//д����
}MyIapRxBuffType;
__IAPEXT MyIapRxBuffType MyIapRxBuff;



//LEDָʾ��״̬����
__packed typedef enum
{
    SLOW = 0,//����: 100ms��,����2S
    NORMAL,  //����: 100ms��,����1S
    FAST,    //����: 100ms��,����200mS
    DOUBLE,  //˫��: 100ms��*2,����1S
    THREEBLE,//����: 100ms��*3,����2S
    LIGHT_PER90, //����: 900ms��,����1S
    LIGHT_ON, //����: һֱ��
    LIGHT_OFF //����: һֱ��
}MyIapLedStatusType;
__IAPEXT MyIapLedStatusType MyIapLedStatus;



//***********************************************************
//ͨ��Э��ṹ����ͷ��
__packed typedef struct
{
    unsigned char Head[3];//ͷ 0x3A,0x5B,0x7C
    unsigned char ProVer;//Э��汾��
    unsigned char DevType;//�豸����
    unsigned char DevAddr;//�豸��ַ
    unsigned char AskFlag;//Ӧ���־
            //���ݰ����𷽣�
            //0x00��������ҪӦ��
            //0x01�������ҪӦ��
            //���ݰ�Ӧ�𷽣�
            //0x02������Ӧ�𣨺����������ݰ���
            //0x03��Ӧ����ɣ��ɹ���
            //0x04�����ݴ��������ط�����ֹ
            //0x05���豸æ���޷���Ӧ
    unsigned int DateLen;//�����峤��
}MyProHeadBaseType;

//ͨ��Э��ṹ����ͷ��
__packed typedef struct
{
    unsigned char Crc[2];//У��
    unsigned char Tail;//β 0x7E
}MyProTailBaseType;

//��ʼ����Э��ṹ��US��
__packed typedef struct
{
    unsigned char Cmd[2];//
    unsigned char Tail;//β 0x7E
}MyProCmdUSType;






//��������
__IAPEXT void Iap_Map_Init(void);
__IAPEXT void iap_jump_to_user_app(void);
__IAPEXT void MX_GPIO_Init(void);
__IAPEXT void LedRun(void);
__IAPEXT void led_display_entry(void *parameter);
__IAPEXT void iap_thread_init(void);
__IAPEXT rt_err_t dev_iap_uart_func(rt_device_t dev, rt_size_t size);
__IAPEXT void my_soft_reset(void);
__IAPEXT void iap_uart_dev_init(void);

#endif






