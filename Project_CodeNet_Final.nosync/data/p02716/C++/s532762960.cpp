//by szh
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define SZ(x) (int((x).size()))
#define se second
#define ll long long
#define pq priority_queue
#define MP make_pair
#define pii pair<int,int>
#define mod 998244353
#define debug(x) cerr<<#x<<"="<<x<<'\n'

const ll inf=1e15;

int read() {
  int x=0,w=1;
  char ch=0;
  while (ch<'0'||ch>'9') {
    if (ch=='-') w=-1;
    ch=getchar();
  }
  while (ch>='0'&&ch<='9') {
    x=(x<<3)+(x<<1)+(ch-'0');
    ch=getchar();
  }
  return x*w;
}

const int maxn=2e5+10;

int n;
int a[maxn];

int calc(int x,int op) {
	if (op==0) return (x-1)/2;
	else return (x+1)/2;
}

ll f[maxn*4][2][2][2];


ll getf(int c,int l,int r,int op,int fl,int fr) {
	if (f[c][op][fl][fr]!=-1) return f[c][op][fl][fr];
	if (l==r) {
		if (op==0) {
			if (fl==0&&fr==0) return 0ll;
			else return -inf;
		}
		else {
			if (fl==1&&fr==1) return (ll)a[l];
			else return -inf;
		}
	}
	int mid=(l+r)/2;
	int tmp=calc(r-l+1,op);
	ll &res=f[c][op][fl][fr];
	res=-inf;
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++) {
			if (calc(mid-l+1,i)+calc(r-mid,j)==tmp) {
				for (int a=0;a<2;a++) {
					if (getf(c*2,l,mid,i,fl,a)==-inf) continue;
					for (int b=0;b<2;b++) {
						if (a==1&&b==1) continue;
						res=max(res,getf(c*2,l,mid,i,fl,a)+getf(c*2+1,mid+1,r,j,b,fr));
					}
				}
			}
		} 
//	printf("l=%d r=%d op=%d fl=%d fr=%d res=%lld\n",l,r,op,fl,fr,res);
	return res;
}

int main(){
	for (int i=0;i<maxn*4;i++)
		for (int j=0;j<2;j++)
			for (int a=0;a<2;a++)
				for (int b=0;b<2;b++) f[i][j][a][b]=-1; 
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	ll ans=-inf;
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++) 
			ans=max(ans,getf(1,1,n,(n%2)^1,i,j));
	printf("%lld",ans);
	return 0;
}
