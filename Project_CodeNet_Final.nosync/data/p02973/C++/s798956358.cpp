#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<bits/stdc++.h>
#define ll long long
#define re register
using namespace std;
struct ios{
	template <typename ty> inline ios& operator >> (ty &x)
	{
		register int f=1;x=0;register char c=getchar();
		for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
		for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
		x*=f;return *this;
	}
	template <typename ty>  inline ios& operator << (ty x)
	{
		if(x<0) x=-x,putchar('-');
		if(x>9) *this << x/10;
		putchar(x%10+48);
		return *this;
	}
	inline ios& operator << (char x){putchar(x);return *this;}
}io;
const int N = 2e5+5;
multiset <int> s;
int n,a[N],k;
int main()
{
	io>>n;
	for(register int i=1;i<=n;i++) io>>a[i];
	s.insert(a[1]);
	for(register int i=2;i<=n;i++)
	{
		multiset <int>::iterator it = s.lower_bound(a[i]);
//		printf("get %d,begin = %d\n",*it,*s.begin());
		if(it != s.begin()) s.erase(--it);
		s.insert(a[i]);
//		for(multiset <int>::iterator itr = s.begin();itr!=s.end();++itr) printf("%d ",*itr);puts("");
	}
	io<<s.size();
}