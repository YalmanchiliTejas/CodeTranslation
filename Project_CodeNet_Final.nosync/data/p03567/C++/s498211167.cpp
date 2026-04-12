#include<bits/stdc++.h>
#define For(i,a,b) for(i=(a);i<=(b);++i)
#define Forward(i,a,b) for(i=(a);i>=(b);--i)
using namespace std;
template<typename T>inline void read(T &x)
{
	T s=0,f=1;char k=getchar();
	while(!isdigit(k)&&(k^'-'))k=getchar();
	if(!isdigit(k)){f=-1;k=getchar();}
	while(isdigit(k)){s=s*10+(k^48);k=getchar();}
	x=s*f;
}
void file()
{
	#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	#endif
}
char x;
bool a;
int main()
{
	while(scanf("%c",&x)!=EOF)
	{
		if(isupper(x))x-='A'-'a';
		if(x=='a')a=true;
		else
		{
			if(a&&x=='c')
			{
				printf("Yes\n");
				return 0;
			}
			a=false;
		}
	}
	printf("No\n");
	return 0;
}

