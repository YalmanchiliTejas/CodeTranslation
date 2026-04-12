#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define int long long
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
const int mod=1e9+7;
const int inv=500000004;
int n,sum;
int a[200010];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],sum=(sum+a[i])%mod;
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+a[i]*(sum+mod-a[i])%mod)%mod;
	}
	cout<<ans*inv%mod<<endl;
	return 0;
}
