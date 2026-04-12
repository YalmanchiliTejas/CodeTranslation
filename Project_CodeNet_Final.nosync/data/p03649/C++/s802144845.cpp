#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <queue>
#include <bitset>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PII pair<LL,LL>
#define sqr(x) (x)*(x)
#define FOR(i,a,b) for (LL i=(a);i<=(b);++i)
#define ROF(i,b,a) for (LL i=(b);i>=(a);--i)
typedef long long LL;
inline LL read(){
	LL x=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}

const LL MAXN=300005,INF=10000000000000000LL;
LL n,m,a[MAXN],b[MAXN];
int main(){
	n=read(); m=0;
	FOR(i,1,n) a[i]=read();
	while (1){
		sort(a+1,a+1+n);
		FOR(i,1,n) b[i]=a[i]/n;
		//FOR(i,1,n) cout<<a[i]<<' '<<b[i]<<endl;
		LL k=n;
		while (k>1&&b[k-1]==b[k]) k--;
		//cout<<k<<endl;
		if (k==1) {
			m+=n*(a[n]-n+1);
			break;
		}
		LL x=(a[k]-a[k-1])/(n+1),y=n-k+1;
		if (x==0) x++;
		m+=x*y;
		FOR(i,1,k-1) a[i]+=x*y;
		FOR(i,k,n) a[i]-=(n-y+1)*x;
	}
	cout<<m<<endl;
	
	return 0;
}

/*
*/
