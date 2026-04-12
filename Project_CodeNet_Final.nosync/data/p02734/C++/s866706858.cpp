#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cctype>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#define lc (x<<1)
#define rc (x<<1|1)
#define gc getchar()//(p1==p2&&(p2=(p1=buf)+fread(buf,1,size,stdin),p1==p2)?EOF:*p1++)
#define mk make_pair
#define pi pair<int,int>
using namespace std;
typedef long long ll;
const int N=3010,size=1<<20,mod=998244353;

//char buf[size],*p1=buf,*p2=buf;
template<class o> void qr(o &x) {
	char c=gc; x=0; int f=1;
	while(!isdigit(c)){if(c=='-')f=-1; c=gc;}
	while(isdigit(c)) x=x*10+c-'0',c=gc;
	x*=f;
}
template<class o> void qw(o x) {
	if(x/10) qw(x/10);
	putchar(x%10+'0');
}
template<class o> void pr1(o x) {
	if(x<0)x=-x,putchar('-');
	qw(x); putchar(' ');
}
template<class o> void pr2(o x) {
	if(x<0)x=-x,putchar('-');
	qw(x); puts("");
}

int n,m;
ll f[N],ans;

int main() {
	qr(n); qr(m); 
	for(int i=1,x;i<=n;i++) {
		qr(x); f[0]++; if(x>m) continue;
		ans+=1LL*(n-i+1)*f[m-x]%mod;
		for(int j=m-x;j>=0;j--) (f[j+x]+=f[j])%=mod;
	}
	pr2(ans%mod);
	return 0;
}
