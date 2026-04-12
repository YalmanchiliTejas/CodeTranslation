#include<bits/stdc++.h>
#define fs first
#define se second
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef double db;

const int maxn=5e5+5;
const ll inf=0x3f3f3f3f;
const ll mod=998244353;

ll dp[maxn];
ll a[maxn];
int main(){
	int n,s;
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		dp[0]++;
		for(int j=s;j>=a[i];j--){
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
		ans=(ans+dp[s])%mod;
	}
	printf("%lld",ans);
	return 0;
}