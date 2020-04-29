#include<stdio.h>
#include<stdlib.h> 
#include<iostream>
#include<cstring>
#include<time.h>
#include<cmath>
#include<fstream>
using namespace std;

int max_number;//所取最大数 
int count_numbers;//计算的数量 
int brackets_operation;//括号运算标志 
int decimal_operation;//小数运算标志 
char operation[4]={'+','-','*','/',}; //运算符 
int ope;   //用1,2,3,4,以及其他数字来决定使用的运算符 
int output_form;  //文件输出还是仅只是屏幕输出 
void integer_count(); //整数四则运算 
void decimal_count(); //小数四则运算 
using namespace std;
ofstream outfile;  //写入文件 

int main()
{
	cout<<"*****---欢迎进入小学生四则运算出题系统---*****"<<endl;
	cout<<"**********************************************"<<endl;
	cout<<"请输入要计算的题目数量："<<endl;
	cin>>count_numbers;
	cout<<"请输入最大数："<<endl;
	cin>>max_number;
	cout<<"请输入所要进行的运算："<<endl;
	cout<<"1代表+ 2代表- 3代表* 4代表/ 其他数字代表随机抽取："<<endl;
	cin>>ope;
	cout<<"请输入1选择整数运算，或者输入2代表小数运算："<<endl;
	cin>>decimal_operation;
	cout<<"请输入1代表不需要括号，输入2代表需要括号"<<endl;
	cin>>brackets_operation;
	cout<<"请输入1代表输出到屏幕并输出到文件 输入2代表仅输出到屏幕上："<<endl;
	cin>>output_form;
	if(output_form==1)
	{
		outfile.open("arithmetic.txt");  //生成的算式写入"arithmetic.txt"文件 
	 } 
	if(decimal_operation==1) //整数运算 
	{
		srand((unsigned int)time(NULL)); 
		//rand()函数每次启动程序产生的随机数都相等，在用srand(unsigned int)输入种子数后产生的才不一样
		for(int i=0;i<count_numbers;i++)
		{
			integer_count();
		}
	}
	else       //小数运算 
	{
		srand((unsigned int)time(NULL));
		for(int i=0;i<count_numbers;i++)
		{
			decimal_count();
		}
	}
	outfile.close(); //关闭文件 
	cout<<"*********************************************"<<endl;
	cout<<"*****---感谢使用，好好学习，天天向上!---*****"<<endl; 
	return 0;
}

void  integer_count()//整数四则运算 
{
	int numb1,numb2,numb3;       //三项运算式 
	numb1=(rand()%max_number)+1; //rand()函数会产生范围为0至32767的随机数，%让它与最大数求余,再加一 
	numb2=(rand()%max_number)+1; //所以numb1,numb2,numb3范围为1-max_number 
	numb3=(rand()%max_number)+1;
	int op1,op2;   // op1.op2在0-3这四个数取值，分别决定+，-，*，/运算 
	op1=rand()%4; 
	op2=rand()%4;
	if(brackets_operation==1) //括号标志为1，进行无括号运算 
	{
		switch(ope) //1为+，2为-，3为*，4为/，其他为随机运算 
		{
		case 1:
			cout<<numb1<<"+"<<numb2<<"+"<<numb3<<"="<<endl;
			outfile<<numb1<<"+"<<numb2<<"+"<<numb3<<"="<<endl;
            break;
		case 2:
			cout<<numb1<<"-"<<numb2<<"-"<<numb3<<"="<<endl;
			outfile<<numb1<<"-"<<numb2<<"-"<<numb3<<"="<<endl;
		    break;
		case 3:
			cout<<numb1<<"*"<<numb2<<"*"<<numb3<<"="<<endl;
			outfile<<numb1<<"*"<<numb2<<"*"<<numb3<<"="<<endl;
		    break;
		case 4:
			cout<<numb1<<"/"<<numb2<<"/"<<numb3<<"="<<endl;
			outfile<<numb1<<"/"<<numb2<<"/"<<numb3<<"="<<endl;
		    break;
		default:
			cout<<numb1<<operation[op1]<<numb2<<operation[op2]<<numb3<<"="<<endl;
			outfile<<numb1<<operation[op1]<<numb2<<operation[op2]<<numb3<<"="<<endl;
		}
	}
	else //否则，进行括号运算 
	{
		int temp;     //temp决定括号的前后 
		temp=rand()%2;//temp取值为0和1 
		if(temp==0)   //在前面两个运算式加括号 
		{
			switch(ope)
			{
			  case 1:
				cout<<"("<<numb1<<"+"<<numb2<<")"<<"+"<<numb3<<"="<<endl;
				outfile<<"("<<numb1<<"+"<<numb2<<")"<<"+"<<numb3<<"="<<endl;
			    break;
			  case 2:
				cout<<"("<<numb1<<"-"<<numb2<<")"<<"-"<<numb3<<"="<<endl;
				outfile<<"("<<numb1<<"-"<<numb2<<")"<<"-"<<numb3<<"="<<endl;
			    break;
			  case 3:
				cout<<"("<<numb1<<"*"<<numb2<<")"<<"*"<<numb3<<"="<<endl;
				outfile<<"("<<numb1<<"*"<<numb2<<")"<<"*"<<numb3<<"="<<endl;
			    break;
			  case 4:
				cout<<"("<<numb1<<"/"<<numb2<<")"<<"/"<<numb3<<"="<<endl;
				outfile<<"("<<numb1<<"/"<<numb2<<")"<<"/"<<numb3<<"="<<endl;
			    break;
			  default:
				cout<<"("<<numb1<<operation[op1]<<numb2<<")"<<operation[op2]<<numb3<<"="<<endl;
				outfile<<"("<<numb1<<operation[op1]<<numb2<<")"<<operation[op2]<<numb3<<"="<<endl;
			}
		}
		else            //在后面两个运算式加括号 
		{
		    switch(ope) //1为+，2为-，3为*，4为/，其他为随机运算 
		    {
			  case 1:
				cout<<numb1<<"+"<<"("<<numb2<<"+"<<numb3<<")"<<"="<<endl;
				outfile<<numb1<<"+"<<"("<<numb2<<"+"<<numb3<<")"<<"="<<endl;
			    break;
			  case 2:
				cout<<numb1<<"-"<<"("<<numb2<<"-"<<numb3<<")"<<"="<<endl;
				outfile<<numb1<<"-"<<"("<<numb2<<"-"<<numb3<<")"<<"="<<endl;
			    break;
			  case 3:
				cout<<numb1<<"*"<<"("<<numb2<<"*"<<numb3<<")"<<"="<<endl;
				outfile<<numb1<<"*"<<"("<<numb2<<"*"<<numb3<<")"<<"="<<endl;
			    break;
			  case 4:
				cout<<numb1<<"/"<<"("<<numb2<<"/"<<numb3<<")"<<"="<<endl;
				outfile<<numb1<<"/"<<"("<<numb2<<"/"<<numb3<<")"<<"="<<endl;
			    break;
			  default:
				cout<<numb1<<operation[op1]<<"("<<numb2<<operation[op2]<<numb3<<")"<<"="<<endl;
				outfile<<numb1<<operation[op1]<<"("<<numb2<<operation[op2]<<numb3<<")"<<"="<<endl;
			}	
		}
	}
 } 
 
 void decimal_count()           // 小数四则运算 
 {
 	double numb4,numb5,numb6;   //定义浮点数类型的三个运算式 
 	numb4=(double)rand()/RAND_MAX*max_number+1; //产生1.0-max_number的浮点数 
 	numb5=(double)rand()/RAND_MAX*max_number+1;
 	numb6=(double)rand()/RAND_MAX*max_number+1;
 	int op1,op2;                // op1.op2在0-3这四个数取值，分别决定+，-，*，/运算 
 	op1=rand()%4;
 	op2=rand()%4;
 	if(brackets_operation==1)   //括号标志为1，进行无括号运算 
	{
		switch(ope) 
		{
		case 1:
			cout<<numb4<<"+"<<numb5<<"+"<<numb6<<"="<<endl;
			outfile<<numb4<<"+"<<numb5<<"+"<<numb6<<"="<<endl;
            break;
		case 2:
			cout<<numb4<<"-"<<numb5<<"-"<<numb6<<"="<<endl;
			outfile<<numb4<<"-"<<numb5<<"-"<<numb6<<"="<<endl;
		    break;
		case 3:
			cout<<numb4<<"*"<<numb5<<"*"<<numb6<<"="<<endl;
			outfile<<numb4<<"*"<<numb5<<"*"<<numb6<<"="<<endl;
		    break;
		case 4:
			cout<<numb4<<"/"<<numb5<<"/"<<numb6<<"="<<endl;
			outfile<<numb4<<"/"<<numb5<<"/"<<numb6<<"="<<endl;
		    break;
		default:
			cout<<numb4<<operation[op1]<<numb5<<operation[op2]<<numb6<<"="<<endl;
			outfile<<numb4<<operation[op1]<<numb5<<operation[op2]<<numb6<<"="<<endl;
		}
	}
	else//否则，进行括号运算 
	{
		int temp;      //temp决定括号的前后 
		temp=rand()%2; //取值为0和1 
		if(temp==0)    //temp为0括号在前面两个运算式 
		{
			switch(ope)
			{
			  case 1:
				cout<<"("<<numb4<<"+"<<numb5<<")"<<"+"<<numb6<<"="<<endl;
				outfile<<"("<<numb4<<"+"<<numb5<<")"<<"+"<<numb6<<"="<<endl;
			    break;
			  case 2:
				cout<<"("<<numb4<<"-"<<numb5<<")"<<"-"<<numb6<<"="<<endl;
				outfile<<"("<<numb4<<"-"<<numb5<<")"<<"-"<<numb6<<"="<<endl;
			    break;
			  case 3:
				cout<<"("<<numb4<<"*"<<numb5<<")"<<"*"<<numb6<<"="<<endl;
				outfile<<"("<<numb4<<"*"<<numb5<<")"<<"*"<<numb6<<"="<<endl;
			    break;
			  case 4:
				cout<<"("<<numb4<<"/"<<numb5<<")"<<"/"<<numb6<<"="<<endl;
				outfile<<"("<<numb4<<"/"<<numb5<<")"<<"/"<<numb6<<"="<<endl;
			    break;
			  default:
				cout<<"("<<numb4<<operation[op1]<<numb5<<")"<<operation[op2]<<numb6<<"="<<endl;
				outfile<<"("<<numb4<<operation[op1]<<numb5<<")"<<operation[op2]<<numb6<<"="<<endl;
			}
		}
		else    //否则括号在后面两个运算式 
		{
		    switch(ope)
		    {
			  case 1:
				cout<<numb4<<"+"<<"("<<numb5<<"+"<<numb6<<")"<<"="<<endl;
				outfile<<numb4<<"+"<<"("<<numb5<<"+"<<numb6<<")"<<"="<<endl;
			    break;
			  case 2:
				cout<<numb4<<"-"<<"("<<numb5<<"-"<<numb6<<")"<<"="<<endl;
				outfile<<numb4<<"-"<<"("<<numb5<<"-"<<numb6<<")"<<"="<<endl;
			    break;
			  case 3:
				cout<<numb4<<"*"<<"("<<numb5<<"*"<<numb6<<")"<<"="<<endl;
				outfile<<numb4<<"*"<<"("<<numb5<<"*"<<numb6<<")"<<"="<<endl;
			    break;
			  case 4:
				cout<<numb4<<"/"<<"("<<numb5<<"/"<<numb6<<")"<<"="<<endl;
				outfile<<numb4<<"/"<<"("<<numb5<<"/"<<numb6<<")"<<"="<<endl;
			    break;
			  default:
				cout<<numb4<<operation[op1]<<"("<<numb5<<operation[op2]<<numb6<<")"<<"="<<endl;
				outfile<<numb4<<operation[op1]<<"("<<numb5<<operation[op2]<<numb6<<")"<<"="<<endl;
			}	
		}
	}
 }
