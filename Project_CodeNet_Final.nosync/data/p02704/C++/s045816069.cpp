//This program is written by Brian Peng.
#pragma GCC optimize("Ofast","inline","no-stack-protector")
#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define Rd(a) (a=rd())
#define Gc(a) (a=getchar())
#define Pc(a) putchar(a)
int rd(){
	int x;char c(getchar());bool k;
	while(!isdigit(c)&&c^'-')if(Gc(c)==EOF)exit(0);
	c^'-'?(k=1,x=c&15):k=x=0;
	while(isdigit(Gc(c)))x=x*10+(c&15);
	return k?x:-x;
}
void wr(int a){
	if(a<0)Pc('-'),a=-a;
	if(a<=9)Pc(a|'0');
	else wr(a/10),Pc((a%10)|'0');
}
signed const INF(0x3f3f3f3f),NINF(0xc3c3c3c3);
long long const LINF(0x3f3f3f3f3f3f3f3fLL),LNINF(0xc3c3c3c3c3c3c3c3LL);
#define Ps Pc(' ')
#define Pe Pc('\n')
#define Frn0(i,a,b) for(signed i(a);i<(b);++i)
#define Frn1(i,a,b) for(signed i(a);i<=(b);++i)
#define Frn_(i,a,b) for(signed i(a);i>=(b);--i)
#define Mst(a,b) memset(a,b,sizeof(a))
#define File(a) freopen(a".in","r",stdin),freopen(a".out","w",stdout)
#define N (510)
#define B(a) (((a)>>k)&1)
int n,a[N][N],u[N],v[N];
bool s[N],t[N];
bool slv(int k);
signed main(){
	Rd(n);
	Frn1(i,1,n)Rd(s[i]);
	Frn1(i,1,n)Rd(t[i]);
	Frn1(i,1,n)Rd(u[i]);
	Frn1(i,1,n)Rd(v[i]);
	Frn0(k,0,64)if(!slv(k))printf("-1"),exit(0);
	Frn1(i,1,n){Frn1(j,1,n)wr(a[i][j]),Ps;Pe;}
	exit(0);
}
bool slv(int k){
	bool r0(0),r1(0),c0(0),c1(0);
	vector<signed>ar,ac,er0,er1,ec0,ec1;
	Frn1(i,1,n)if(!s[i]&&B(u[i])){r1=1;Frn1(j,1,n)a[i][j]|=1ULL<<k;}
		else if(s[i]&&!B(u[i]))r0=1;
		else ar.push_back(i);
	Frn1(j,1,n)if(!t[j]&&B(v[j])){c1=1;Frn1(i,1,n)a[i][j]|=1ULL<<k;}
		else if(t[j]&&!B(v[j]))c0=1;
		else ac.push_back(j);
	if(r0&&c1||r1&&c0)return 0;
	for(int i:ar)if(B(u[i])&&!c1)er1.push_back(i);
		else if(!B(u[i])&&!c0)er0.push_back(i);
	for(int j:ac)if(B(v[j])&&!r1)ec1.push_back(j);
		else if(!B(v[j])&&!r0)ec0.push_back(j);
	if(ar.empty())return ec0.empty()&&ec1.empty();
	if(ac.empty())return er0.empty()&&er1.empty();
	if(ar.size()==1){
		if(ec0.size()==ac.size()&&!er1.empty()||ec1.size()==ac.size()&&!er0.empty())return 0;
		if(er1.empty())for(int j:ec1)a[ar[0]][j]|=1ULL<<k;
		else{for(int j:ac)a[ar[0]][j]|=1ULL<<k;for(int j:ec0)a[ar[0]][j]^=1ULL<<k;}
		return 1;
	}
	if(ac.size()==1){
		if(er0.size()==ar.size()&&!ec1.empty()||er1.size()==ar.size()&&!ec0.empty())return 0;
		if(ec1.empty())for(int i:er1)a[i][ac[0]]|=1ULL<<k;
		else{for(int i:ar)a[i][ac[0]]|=1ULL<<k;for(int i:er0)a[i][ac[0]]^=1ULL<<k;}
		return 1;
	}
	if(ar.size()>=ac.size())Frn0(i,0,ar.size())a[ar[i]][ac[i%ac.size()]]|=1ULL<<k;
	else Frn0(j,0,ac.size())a[ar[j%ar.size()]][ac[j]]|=1ULL<<k;
	return 1;
}
