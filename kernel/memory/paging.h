#ifndef PAGING_H
#define PAGING_H

#include "../cpu/types.h"
#include "../cpu/isr.h"

#define PAGE_SIZE 4096

/*typedef struct page{
		u32 present				:1;
		u32 rw						:1;
		u32 kernel_space	:1;
		u32 accessed			:1;
		u32 dirty					:1;
		u32 unused				:7;
		u32 frame					:20;
} page_t; */


typedef struct page_table{
		u32 pages[1024];
} page_table_t;

typedef struct page_directory{
		u32 page_tables[1024];
} page_dir_t;
typedef struct page_directory_interface{
		page_dir_t dir;
		page_table_t* page_tables;
		u32 page_dir_ph_address;
} page_dir_interface_t;
void init_paging();


void switch_page_dir(page_dir_t* new_dir);

u32 get_page(u32 addres, page_dir_t* dir, u8 make);

void page_fault(registers_t regs);
#endif
