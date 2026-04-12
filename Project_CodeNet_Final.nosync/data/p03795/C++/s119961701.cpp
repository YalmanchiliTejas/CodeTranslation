#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>

using namespace std;

inline int read(){
    int s=0,w=1,ch=getchar();
    while(ch<'0'||ch>'9')if(ch=='-')w=-1,ch=getchar();
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return s*w;
}

inline void write(int x)
{
    char F[16]={};int cnt=0;
    if(x==0)
	{
	    putchar('0');
	    return;
	}
    if(x<0)putchar('-');
    while(x)
    {
        F[cnt++]=x%10+'0';
        x/=10;
    }
    while(cnt>0)putchar(F[--cnt]);
}


int main()
{
	//freopen_init();
	int reads=read();
	write(reads*800-reads/15*200);
	
	putchar('\n');
	return 0;
}
