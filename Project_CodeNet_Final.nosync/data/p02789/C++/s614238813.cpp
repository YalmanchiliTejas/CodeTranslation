#include<bits/stdc++.h>
#define del(a,i) memset(a,i,sizeof(a))
#define ll long long
#define inl inline
#define il inl void
#define it inl int
#define ill inl ll
#define re register
#define ri re int
#define rl re ll
#define INF 0x3f3f3f3f
#define lowbit(x) (x&(-x))
#define mid ((l+r)>>1)
using namespace std;
template<class T>il read(T &x){
	x=0;int f=1;char k=getchar();
	for(;k>'9'||k<'0';k=getchar()) if(k=='-') f=-1;
	for(;k>='0'&&k<='9';k=getchar()) x=x*10+k-'0';
	x*=f;
}
template<class T>il _print(T x){
	if(x>9) _print(x/10);
	putchar(x%10+'0');
}
template<class T>il print(T x){
	if(x<0) putchar('-'),x=-x;
	_print(x);
}
int n,m;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	read(n),read(m);
	puts(n==m?"Yes":"No");
	return 0;
}