#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define LL long long
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
const int MOD=998244353;
int n,s,ans;
int a[3010];
int dp[4010];
int main(){
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
        for(int j=s-a[i];j>0;j--)
			dp[j+a[i]]=(dp[j+a[i]]+dp[j])%MOD;
		dp[a[i]]=(dp[a[i]]+i)%MOD;
		ans=(ans+dp[s])%MOD;
	}
	cout<<ans<<endl;
	return 0;
}
