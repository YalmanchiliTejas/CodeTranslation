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
const int N=2e5+5;
const int M=1e9+7;
 
ll dp[N][3];
 
ll minim=-1ll*(1e17);
 
void solve(){
	int n;
	sfi(n)
 
	vector<ll> v(n);
 
	ll sum1=0,sum2=0;
 
	f(i,0,n){
		sfl(v[i])
 
		if(i&1)
			sum1+=v[i];
		else
			sum2+=v[i];
	}
 
	//cout<<sum1<<" "<<sum2<<endl;
 
	
 
	dp[0][0]=v[0];
	dp[0][1]=minim;
	dp[0][2]=minim;
 
	dp[1][0]=v[1];
	dp[1][1]=minim;
	dp[1][2]=minim;
 
	f(i,2,n){
		dp[i][0]=v[i]+dp[i-2][0];
 
		dp[i][1]=minim;
		dp[i][2]=minim;
 
		dp[i][1]=max(dp[i][1],v[i]+dp[i-2][1]);
		dp[i][2]=max(dp[i][2],v[i]+dp[i-2][2]);
 
		if(i==2){
			dp[i][1]=v[2];
			//continue;
		}
 
		for(int j=i-3;j>=max(i-4,0);j--){
 
			if(j==(i-3)){
				dp[i][1]=max(dp[i][1],v[i]+dp[j][0]);
			}
 
			if(j==i-4){
				if(i==26){
					//cout<<j<<" "<<dp[j][0]<<endl;
				}
				dp[i][2]=max(dp[i][2],v[i]+dp[j][0]);
			}
			else if(j==i-3){
				if(i==26){
					//cout<<j<<" "<<dp[j][1]<<endl;
				}
				dp[i][2]=max(dp[i][2],v[i]+dp[j][1]);
			}
		}
	}

	ll ans=-1ll*llinf;
 	
 	if(n%2==1){
 		ans=dp[n-1][2];
		ans=max(ans,dp[n-1][1]);
		ans=max(ans,dp[n-2][0]);
		ans=max(ans,dp[n-2][1]);
		ans=max(ans,dp[n-3][0]);
 	}
	
 	else{
 		ans=dp[n-1][1];
 		ans=max(dp[n-1][0],ans);
 		ans=max(dp[n-2][0],ans);
 	}

	f(i,0,n){

	}
 
	pfln(ans)
 
}
 
int main(){	
	
	solve();
	return 0;	
}