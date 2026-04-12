//#pragma GCC optimize(2)
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<cstdlib>
#include<string>
#include<cstring>
#include<bitset>
#define heap priority_queue<int,vector<int>,greater<int> >
#define _heap priority_queue<int,vector<int>,less<int> >
#define _for(a,b,c) for((a)=(b);(a)<=(c);++(a))
#define __for(a,b,c) for((a)=b;(a)>=(c);--(a))
#define _init(a,b) memset((a),(b),sizeof (a))
#define LL long long
#define mod 1e9+7
#define INF 0x3f3f3f3f
using namespace std;

namespace FastIO {
	template<typename tp> inline void read(tp &x) {
		x=0; register char c=getchar(); register bool f=0;
		for(;c<'0'||c>'9';f|=(c=='-'),c = getchar());
		for(;c>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0',c = getchar());
		if(f) x=-x;
	}
	template<typename tp> inline void write(tp x) {
		if (x==0) return (void) (putchar('0'));
		if (x<0) putchar('-'),x=-x;
		int pr[20]; register int cnt=0;
		for (;x;x/=10) pr[++cnt]=x%10;
		while (cnt) putchar(pr[cnt--]+'0');
	}
	template<typename tp> inline void writeln(tp x) {
		write(x);
		putchar('\n');
	}
}
using namespace FastIO;

//------------Coding Area------------
struct node{
	int d,a;
};
bool cmp(node a,node b){
	return a.d<b.d;
}
int d[200010],ans[200010];
node e[200010];
int n;
int main(){
	read(n);
	int cache=(n+1)/2;
	for(int i=1;i<=n;++i) read(d[i]);
	for(int i=1;i<=n;++i) e[i].d=d[i],e[i].a=i;
	sort(e+1,e+n+1,cmp);
	int mid1=e[cache].d,mid2=e[cache+1].d;
	for(int i=1;i<=n;++i) 
		if(i>cache) ans[e[i].a]=mid1; else ans[e[i].a]=mid2;
	for(int i=1;i<=n;++i) writeln(ans[i]);
	return 0;
}