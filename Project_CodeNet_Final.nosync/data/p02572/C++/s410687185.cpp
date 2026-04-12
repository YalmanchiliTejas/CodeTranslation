#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;

template<class T> inline void checkmin(T &a,const T &b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,const T &b){if(b>a) a=b;}

const int maxn=2e5+10;
const ll mod=1e9+7;

ll sum[maxn],a[maxn],ans=0;
int n;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sum[0]=a[0];
	for(int i=1;i<n;i++) sum[i]=sum[i-1]+a[i],sum[i]%=mod;
	for(int i=0;i<n-1;i++) ans+=a[i]*((sum[n-1]-sum[i]+mod)%mod)%mod,ans%=mod;
	printf("%d\n",ans);
	return 0;
}
