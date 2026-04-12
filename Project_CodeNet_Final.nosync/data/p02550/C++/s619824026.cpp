#include<bits/stdc++.h>
using namespace std;
#define gc() getchar()
#define pc(a) putchar(a)
#define int long long
#define inf (1ll<<60)
inline int read()
{
    int x=0,f=1;
    char c=gc();
    while(c>'9'||c<'0')
    {
        if(c=='-') f=-f;
        c=gc();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=gc();
    return x*f;
}
int Num[25];
inline void write(int x)
{
    if(!x) {pc('0');return;}
    if(x<0) x=-x,pc('-');
    int top=0;
    while(x) Num[++top]=x%10,x/=10;
    while(top) pc(Num[top--]+'0');
    return;
}
#define ma 300005
int su[ma];
map<int,int> vis;
signed main()
{
	int n=read(),x=read(),m=read();
	int lop=0,ans=0;
	int lopp=0,st=1;
	while(1)
	{
		lop++;
		if(vis[x]) 
		{
			lopp=lop-vis[x],st=vis[x];
			break;	
		}
		ans=(ans+x);
		vis[x]=lop;
		su[lop]=(su[lop-1]+x);
		x=(x*x)%m;
		if(lop>=n)
		{
			lopp=lop;
			break;
		} 
	}
	write((su[st-1]+((n-st+1)/lopp)*(ans-su[st-1])+su[(n-st+1)%lopp+st-1]-su[st-1]));
}







