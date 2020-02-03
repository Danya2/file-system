#ifndef DANYA_DEBUG_H
#define DANYA_DEBUG_H

#define EXT4_DAX_DBG 1
//#define CONFIG_FS_DAX 1 // need to enable when editing the ext4_dax_fault() in VScode IDE
#define ENTIRE_MAPPING 0 

int dax_fault_mmapping(struct vm_area_struct *vma, struct vm_fault *vmf);
long long int* split_segments(unsigned long int predict_minsize, unsigned long int predict_maxsize, int segs_nums);
/* in order to enable the debug print */
#if EXT4_DAX_DBG
#define DAX_PRINT(pri, pri_str, fmt, arg...) \
    printk(pri KBUILD_MODNAME "[%s] <%s:%d> " fmt, pri_str, __FUNCTION__, __LINE__, ##arg)
#define dax_dbg(fmt, arg...) DAX_PRINT(KERN_INFO, "DEBUG", fmt, ##arg)
#endif

#define record_nums 8  /* define the initial predict record numbers */

struct pre_record_parameter {
//    int record_nums;
    long long int* pre_record_read;
    long long int* pre_record_write;
};

#endif 

