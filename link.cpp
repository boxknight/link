#include<stdlib.h>
#include"link.h"
/* 
* �����б�
* ������������
* ��Xλ�ú�����һ���ڵ�
* ��Xλ�ò���һ������
* ɾ��Xλ����Yλ�õĽڵ�
* ��ѯXλ�ýڵ������
* ����Xλ�ýڵ������
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
}//��������ΪN������

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
}//��Nλ�ò���һ���ڵ�

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
}//��Nλ�ò���һ������

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
}//ɾ��STλ����FIλ�õĽڵ�

//*************************************************************************************

int INQUIRE(Link HAND, int N){
	int num;
	Link TEMP;
	TEMP = HAND;

	for (num = 1; num < N; num++)
		TEMP.next = TEMP.next->next;

	return TEMP.obj;
}//��ѯNλ�ýڵ������

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
}//����Nλ�ýڵ������

 /*
 * Copyright(c) 2018, KUN
 * All rights reserved.

 * �汾             1.0
 * �ļ�            ����
 * ʹ�÷���       ���ļ�
 * �������  2018/05/04
 * ͷ�ļ�        link.h

 */
