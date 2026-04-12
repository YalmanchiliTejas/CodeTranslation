#include<bits/stdc++.h>
using namespace std;
int x,y,z;
inline int read()
{
	int n_read=0,o_read=1;
	char c_read=getchar();
	while(c_read<'0'||c_read>'9')
	{
		if(c_read=='-')
			o_read=-1;
		c_read=getchar();
	}
	while(c_read>='0'&&c_read<='9')
	{
		n_read=n_read*10+c_read-'0';
		c_read=getchar();
	}
	return n_read*o_read;
}
int main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	x=read(),y=read(),z=read();
	printf("%d\n",(x-z)/(y+z));
	putchar('\n');
	return 0;
}
