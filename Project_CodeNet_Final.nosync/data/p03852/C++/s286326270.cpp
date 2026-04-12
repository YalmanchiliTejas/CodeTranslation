#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	register int number_read=0,if_ok_read=1;
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
inline void write(register int x_write)
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
	char ch=getchar();
	if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
		printf("vowel");
	else
		printf("consonant");
	putchar('\n');
	return 0;
}
