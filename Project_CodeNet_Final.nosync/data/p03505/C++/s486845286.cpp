#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
	register ll number_read=0,if_ok_read=1;
	char ch_read=getchar();
	while(ch_read<'0'||ch_read>'9')
	{
		if(ch_read=='-')
			if_ok_read=-1;
		ch_read=getchar();
	}
	while(ch_read>='0'&&ch_read<='9')
	{
		number_read=number_read*10+ch_read-'0';
		ch_read=getchar();
	}
	return number_read*if_ok_read;
}
inline void write(register ll x_write)
{
    if(x_write<0)
	{
    	putchar('-');
		x_write=-x_write;
	}
    if(x_write>9)
		write(x_write/10);
    putchar(x_write%10+'0');
    return ;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ll k=read(),a=read(),b=read(),c=0;
    if(a>=k)
    {
        write(1);
        putchar('\n');
        return 0;
    }
	else 
		if(b>=a)
		{
	        write(-1);
	        putchar('\n');
	        return 0;
	    }
		else 
			if((k-a)%(a-b)>=1)
	        	c=1;
    write(((k-a)/(a-b)+c)*2+1);
	putchar('\n');
	return 0;
}
