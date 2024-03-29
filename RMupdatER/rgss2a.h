/***************************************************************
 * Name:      rgss2a.h
 * Purpose:   Code for RGSS2A/RGSSAD File Handler
 * Author:    gs (gs@bbxy.net)
 * Created:   2009-05-16
 * Copyright: GPLv3
 * License:
 **************************************************************/

#ifndef RGSS2A_H_INCLUDED
#define RGSS2A_H_INCLUDED

//#define RGSS2A_MAGIC_KEY	0xDEADCAFE
#define RGSS2A_MAGIC_KEY	0x19940618

#include "stdlib.h"

class rgss2a{
	private:
		FILE* fp_r;
		FILE* fp_w;
		long magic_key;

		static long magic_key_E(long magic_key_orn);		// E变换
		long magic_key_E_path(long magic_key_orn);
		long magic_key_E_pathsize(long magic_key_orn);
		long magic_key_E_content(long magic_key_orn);
		long magic_key_E_contentsize(long magic_key_orn);
		void encrypt_content(void* buffer, unsigned long buffer_size, long content_magic_key);

	public:
		rgss2a();
		~rgss2a();
		bool OpenRgss2aFile(const char* path);
		bool CreateRgss2aFile(const char* path);
		bool ReadSubFile(char* &filename, void* &content, unsigned long& content_size);
		bool WriteSubFile(const char* filename, void* content, unsigned long content_size);
};
#endif // RGSS2A_H_INCLUDED
