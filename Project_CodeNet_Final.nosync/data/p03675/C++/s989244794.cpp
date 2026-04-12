#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cassert>
#include<cmath>
using namespace std;
#define fi first
#define se second
#define rep(i,s,t) for(int i=(s),_t=(t);i<_t;++i)
#define per(i,s,t) for(int i=(t)-1,_s=(s);i>=_s;--i)
#define debug(x) cerr<<#x<<" == "<<(x)<<endl
#define bug(x) cerr<<#x<<" == "<<(x)<<" "
typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
typedef pair<int,int> pii;
template<class T>inline void rd(T &x){
	x=0;char c;int f=1;
	while(c=getchar(),c<48)if(c=='-')f=-1;
	do x=x*10+(c&15);
	while(c=getchar(),c>47);
	x*=f;
}
template<class T>void pf(T x){
	if(x<0)putchar('-'),x=-x;
	else if(!x){
		putchar('0');
		return ;
	}
	static int stk[100],tp;
	for(tp=0;x;x/=10)stk[tp++]=x%10;
	while(tp)putchar(stk[--tp]^48);
}
template<class T>void ptn(T x){
	pf(x),putchar('\n');
}
template<class T>void ptk(T x){
	pf(x),putchar(' ');
}
template<class T>void Min(T &A,T B){
	if(A>B)A=B;
}
template<class T>void Max(T &A,T B){
	if(A<B)A=B;
}

const int N=(int)2e5+5;
int n,a[N<<1];
int main(){
	rd(n);
	int L=n,R=n;
	rep(i,1,n+1){
		int x;
		rd(x);
		if(i&1)a[--L]=x;
		else a[R++]=x;
	}
	if(n&1)rep(i,L,R)ptk(a[i]);
	else per(i,L,R)ptk(a[i]);
	return 0;
}