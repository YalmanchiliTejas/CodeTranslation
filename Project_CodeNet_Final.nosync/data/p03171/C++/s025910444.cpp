/*input
4
10 80 90 30
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#pragma GCC optimize("unroll-loops,no-stack-protector")
//order_of_key #of elements less than x
// find_by_order kth element
typedef long long int ll;
#define ld long double
#define pii pair<int,int>
#define f first
#define s second
#define pb emplace_back
#define REP(i,n) for(ll i=0;i<n;i++)
#define sz(_a) (ll)(_a.size())
#define FILL(n) memset(n,0,sizeof(n))
#define ALL(_a) _a.begin(),_a.end()
const ll maxn=100005;
const ll maxlg=__lg(maxn)+2;
const ll INF64=8000000000000000000LL;
const int INF=0x3f3f3f3f;
const ll MOD=ll(1e9+7);
const ld PI=acos(-1);
const ld eps=1e-9;
ll mypow(ll a,ll b){
    ll res=1LL;
    while(b){
        if(b&1) res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}
ll dp[3005][3005];
ll arr[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	REP(i,n) cin>>arr[i];
	for(int i=n-1;i>=0;i--){
		for(int j=i;j<n;j++){
			if(i==j) dp[i][j]=arr[i];
			else dp[i][j]=max(arr[j]-dp[i][j-1],arr[i]-dp[i+1][j]);
		}
	}
	cout<<dp[0][n-1];
}