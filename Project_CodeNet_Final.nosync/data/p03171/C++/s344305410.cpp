#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define all(c)  c.begin(), c.end()
#define llv vector< ll >
#define mp make_pair
#define endl "\n"
const int N = (int)3e3+10 ;
const int M = (int)1000000007; 

ll dp[N][N]  , a[N] ;
bool mark[N][N] = {} ;
ll check(int be , int en){
    if(mark[be][en])return dp[be][en] ;
    if(en==be+1){
       mark[be][en]=1 ;
       ll d = abs(a[en]-a[be]) ;
       return dp[be][en] = d ;
    }
    mark[be][en]=1 ;
    return dp[be][en] = max(a[be]-check(be+1 , en) , a[en]-check(be , en-1) ) ;
}

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll n , i ;
    cin >> n ;
    for(i=0 ; i<n; i++){
        cin >> a[i] ;
    }
    if(n==1)cout << a[0] ;
    else cout << check(0,n-1) ;

    return 0 ;
}