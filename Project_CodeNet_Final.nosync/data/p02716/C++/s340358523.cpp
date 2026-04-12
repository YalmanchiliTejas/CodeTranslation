#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF (ll)1e18
#define MOD (ll)1e9+7
#define print(a); for(auto x:a)cout<<x<<" "; cout<<"\n";
#define mset(a); memset(a,0,sizeof(a));

const ll N=(ll)2e5+5;
ll dp[N];
ll arr[N];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    ll sum=arr[1];
    for(int i=2;i<=n;i++){
        if(i&1){
            sum+=arr[i];
            dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
        }else{
            dp[i]=max(sum,dp[i-2]+arr[i]);
        }
    }
    cout<<dp[n]<<"\n";
}
