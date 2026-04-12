#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[200];
int f1(int n[],int num)
{
	int sum=0;
	sum+=n[0];
	sum+=9*(num-1);
//	printf("f1: %d\n",sum);
	if(sum<0) sum=0;
	return sum;
}
int f2(int n[],int num)
{
	int sum=0;
	sum+=(n[0]-1)*9*(num-1);
	sum+=9*9*(num-1)*(num-2)/2;
	int i1,n2[200];
	for(i1=1;n[i1]==0;i1++);
	for(int i=i1;i<num;i++)
	{
		n2[i-i1]=n[i];
	}
//	printf("f2: %d\n",sum);
	sum+=f1(n2,num-i1);
	if(sum<0) sum=0;
	return sum;
}
int f3(int n[],int num)
{
	int sum=0;
	sum+=(n[0]-1)*9*9*(num-1)*(num-2)/2;
	sum+=9*9*9*(num-1)*(num-2)*(num-3)/6;
	int i1,n2[200];
	for(i1=1;n[i1]==0;i1++);
	for(int i=i1;i<num;i++)
	{
		n2[i-i1]=n[i];
	}
//	printf("f3: %d\n",sum);
	sum+=f2(n2,num-i1);
	return sum;
}
int main(void)
{
	scanf("%s",s);
	int n[200];
	for(int i=0;i<strlen(s);i++)
	{
		n[i]=s[i]-'0';
	}
	int k,sum=0,num=strlen(s);
	scanf("%d",&k);
//	printf("%d ",num);
	if(k==1)
	{
		sum=f1(n,num);
	}
	else if(k==2&&num>1)
	{
		sum=f2(n,num);
	}
	else if(k==3&&num>2)
	{
		sum=f3(n,num);
	}
	printf("%d",sum);
}