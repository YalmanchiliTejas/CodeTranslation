#include<bits/stdc++.h>
#include<cassert>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds; 
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
#define pfi(a) printf("%d",a);
#define pfl(a) printf("%lld",a);
#define pfin(a) printf("%d\n",a);
#define pfln(a) printf("%lld\n",a);
#define sfi(a) scanf("%d",&a);
#define sfl(a) scanf("%lld",&a);
#define pb push_back
#define f(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define inf INT_MAX
#define llinf LONG_LONG_MAX

const int MAXN=2e5+1;
const int M=998244353;
 
ll dp[3001][3001],arr[3001]; 


void solve(){
	int n,s;
	sfi(n) sfi(s)

	f(i,1,n+1){
		sfl(arr[i])
	}

	dp[0][0]=1;

	ll ans=0;

	for(int i=1;i<=n;i++){
		for(ll sum=0;sum<=s;++sum){
			dp[i][sum]=dp[i-1][sum];

			if(sum>=arr[i]){
				dp[i][sum]+=dp[i-1][sum-arr[i]];
				dp[i][sum]%=M;
			}

			//dp[i][arr[i]]+=(i);
			dp[i][arr[i]]%=M;
		}

		dp[i][arr[i]]+=(i-1);
	//	cout<<dp[i][s]<<endl;
		ans=(ans+dp[i][s])%M;
	}

	pfln(ans)

}


int main(){	
	
	solve();
	return 0;	
}