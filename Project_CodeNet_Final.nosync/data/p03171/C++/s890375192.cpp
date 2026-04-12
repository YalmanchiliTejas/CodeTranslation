#include <bits/stdc++.h>
using namespace std;
 
 
#define ll long long
#define MOD 1000000007
#define pll             pair<ll,ll>
#define pii             pair<int,int> 
#define mp(a,b)         make_pair(a,b)
#define pb 				push_back
#define vi				vector<int>
#define vl 				vector<long long>
#define vb 				vector<bool>
#define printv(v)		for(auto x : v) cout<<x<<' ';br;
#define FOR(i,a,b) 		for(ll i = a; i <= b ; i++)
#define forn(i,n) 		for(ll i = 0 ; i < n; i++)
#define br 				cout<<endl;
#define testc()			ll t;cin>>t;while(t--)
 
#define fast 			ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF				INT_MAX
#define INFL			LLONG_MAX
#define max1(x,y) (x)>(y)?(x):(y)
#define ss second
#define ff first
#define MAXN 100001

int main(){
    fast
    ll n;
    cin>>n;
    ll arr[n+1];
    FOR(i,1,n)
    cin>>arr[i];
    ll dp[n+1][n+1];
    FOR(i,1,n){
        for(ll j=i;j>0;j--){
            if(i==j)
            dp[i][j]=arr[i];
            else{
                dp[i][j]=max(arr[i]-dp[i-1][j],arr[j]-dp[i][j+1]);
            }
        }
    }
    // FOR(i,1,n){
    //     FOR(j,1,i){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n][1]<<endl;
    return 0;
}