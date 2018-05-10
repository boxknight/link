#include"link.cpp"
#ifndef LINK_H_
#define LINK_H_ 
/*
* Copyright(c) 2018, KUN
* All rights reserved.

* 版本             1.0
* 文件            链表
* 使用方法       见文件
* 完成日期  2018/05/04

*/


//*************************************************************************************
struct Link{
	int obj;
	Link *next;
};
//*************************************************************************************

Link MYLINK(int N);                               //建立长度为N的链表
Link INSERT(Link& HAND, int N, Link& IN);         //在N位置插入一个节点
Link INSERT(Link& HAND, Link& IN, int N);         //在N位置插入一个链表
bool DELETE(Link&, int ST, int FI);               //删除ST位置至FI位置的节点
int INQUIRE(Link, int N);                         //查询N位置节点的数据
bool CHANGE(Link&, int N, int OBJ);               //更改N位置节点的数据

//*************************************************************************************

#endif