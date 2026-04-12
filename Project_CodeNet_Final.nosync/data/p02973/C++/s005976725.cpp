#include<bits/stdc++.h>
#define FOR(i,a,b) for (register int i=a;i<=b;i++)
#define For(i,a,b) for (register int i=a;i>=b;i--)
#define mem(i,j) memset(i,j,sizeof(i))
#define GO(u) for (register int j=f[u];j!=-1;j=nxt[j])
using namespace std;
typedef long long ll;
const int N=2e6+5;
int n,a[N],Ans=0;
multiset <int> s;
multiset <int>::iterator it;
int read()
{
	int x=0,f=1;
	char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') {x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return f*x;
}
int main()
{
	n=read();
	FOR(i,1,n) a[i]=read();
	s.insert(a[1]);
	FOR(i,2,n)
	{
		it=s.lower_bound(a[i]);
		if (it==s.begin()) s.insert(a[i]),Ans++;
		else
		{
			it--;
			int tmp=*it;
			s.erase(s.find(tmp));
			s.insert(a[i]);
		}
	}
	printf("%d\n",Ans+1);
	return 0;
}
/*
6
1 1 2 2 3 3
*/