#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
int n,a,b,k;

int main() {
	read(n); read(k); ll ans=0;
	if (k==0)  {printf("%lld",1LL*n*n); return 0;}
	rep(b,k+1,n) {
		int p=(n-b+1)/b,val=1LL*b*(p+1)+k;
		ans+=1LL*(p+1)*(b-1-k+1)+max(n-val+1,0);
	//	printf("%d %lld\n",b,ans);
	}
	printf("%lld",ans);
	return 0;
}