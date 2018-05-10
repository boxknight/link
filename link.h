#include"link.cpp"
#ifndef LINK_H_
#define LINK_H_ 
/*
* Copyright(c) 2018, KUN
* All rights reserved.

* �汾             1.0
* �ļ�            ����
* ʹ�÷���       ���ļ�
* �������  2018/05/04

*/


//*************************************************************************************
struct Link{
	int obj;
	Link *next;
};
//*************************************************************************************

Link MYLINK(int N);                               //��������ΪN������
Link INSERT(Link& HAND, int N, Link& IN);         //��Nλ�ò���һ���ڵ�
Link INSERT(Link& HAND, Link& IN, int N);         //��Nλ�ò���һ������
bool DELETE(Link&, int ST, int FI);               //ɾ��STλ����FIλ�õĽڵ�
int INQUIRE(Link, int N);                         //��ѯNλ�ýڵ������
bool CHANGE(Link&, int N, int OBJ);               //����Nλ�ýڵ������

//*************************************************************************************

#endif