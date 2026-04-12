#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; 
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define endl "\n"
#define F first
#define S second

#define pq priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>
#define MAX  *max_element
#define MIN  *min_element
#define des_sort(v) sort(v.begin(),v.end(),greater<int>())
 
#define c_ones(number) __builtin_popcountll(number)
#define flip_bits(number) static_cast<unsigned>(~number)
 
#define all(X) X.begin(),X.end()
#define rep(i,n) for(ll i=0;i<n;i++)
#define loop(itr,n) for(itr=n.begin();itr!=n.end();itr++)
 
#define FLUSH fflush(stdout)
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb_ds tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> 
#define mod 1000000007
#define INF 1e18
 
const double PI = acos(-1);
 
bool compare(pair<int,int>a , pair<int,int>b){
	return a.first==b.first ? a.second<b.second : a.first < b.first;
}
 
struct hash_pair{ 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};


int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];
    ll dp[n][n];
    rep(i,n)dp[i][i]=a[i];
    for(int i=1;i<=n;i++){
    	for(int j=0;j<n-i;j++){
    		dp[j][j+i] = max(a[j]-dp[j+1][j+i],a[j+i]-dp[j][j+i-1]);
		}
	}
	cout<<dp[0][n-1]<<endl;
}