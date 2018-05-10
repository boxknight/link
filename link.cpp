#include<stdlib.h>
#include"link.h"
/* 
* 功能列表
* 建立整个链表
* 在X位置后新增一个节点
* 在X位置插入一个链表
* 删除X位置至Y位置的节点
* 查询X位置节点的数据
* 更改X位置节点的数据
*/

//*************************************************************************************

Link MYLINK(int N){
	int i;
	Link HAND;
	Link TEMP;
	N -= 1;
	HAND.next = (Link*)malloc((int)(sizeof(int) + sizeof(Link*)));
	TEMP.next = HAND.next;

	for (i = 1; i < N; i++)
	{
		TEMP.next->next = (Link*)malloc((int)(sizeof(int) + sizeof(Link*)));
		TEMP.next = TEMP.next->next;
	}

	return HAND;
}//建立长度为N的链表

//*************************************************************************************

Link INSERT(Link& HAND, int N, Link& IN){
	int num;
	Link TEMP;
	Link* temp;
	temp = NULL;
	TEMP = HAND;
	for (num = 0; num < N + 1; num++)
	{
		if (num = N - 1)
		{
			temp = TEMP.next;
			TEMP.next = &IN;
		}
		if (num = N)
			IN.next = temp;
		TEMP.next = TEMP.next->next;
	}

	return HAND;
}//在N位置插入一个节点

//*************************************************************************************

Link INSERT(Link& HAND, Link& IN, int N){
	int num;
	Link TEMP;
	Link* temp;
	TEMP = HAND;
	for (num = 1; num < N; num++)
		TEMP.next = TEMP.next->next;
	temp = TEMP.next;
	TEMP.next = &IN;
	for (; TEMP.next == NULL;)
		TEMP.next = TEMP.next->next;
	TEMP.next = temp;

	return HAND;
}//在N位置插入一个链表

//*************************************************************************************

bool DELETE(Link& HAND, int ST, int FI){
	int num;
	Link TEMP, TEMP_FI;
	TEMP = HAND;

	for (num = 1; num < ST; num++)
		TEMP.next = TEMP.next->next;

	TEMP_FI = TEMP;
	for (; num<FI; num++)
		TEMP.next = TEMP.next->next;

	TEMP_FI.next = TEMP.next;

	return 1;
}//删除ST位置至FI位置的节点

//*************************************************************************************

int INQUIRE(Link HAND, int N){
	int num;
	Link TEMP;
	TEMP = HAND;

	for (num = 1; num < N; num++)
		TEMP.next = TEMP.next->next;

	return TEMP.obj;
}//查询N位置节点的数据

//*************************************************************************************

bool CHANGE(Link& HAND, int N, int OBJ){
	int num;
	Link TEMP;
	TEMP = HAND;
	if (N == 1)
		HAND.obj = OBJ;
	if (N != 1)
	{
		for (num = 2; num < N; num++)
			TEMP.next = TEMP.next->next;

		TEMP.next->obj = OBJ;
	}

	return 1;
}//更改N位置节点的数据

 /*
 * Copyright(c) 2018, KUN
 * All rights reserved.

 * 版本             1.0
 * 文件            链表
 * 使用方法       见文件
 * 完成日期  2018/05/04
 * 头文件        link.h

 */
