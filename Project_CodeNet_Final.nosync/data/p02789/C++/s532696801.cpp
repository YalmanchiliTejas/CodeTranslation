#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long int
// #define lli long long int
#define ld long double
#define ff first
#define ss second
#define mp make_pair
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define endl '\n'
#define all(x) x.begin(),x.end()
#define f(i,j,l) for(i=j;i<l;i++)
// #if !defined(ONLINE_JUDGE)
// #include "debugging.h"
// #endif
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// int const mod = 7340033;
int const mod = 1e9+7;
int power(int a,int b,int m){
    int res = 1;
    while(b){
        if(b&1){
            res = res*a;
            res %= m;
        }
        a=a*a;
        a%=m;
        b=b/2;
    }
    return res;
}
 
int inverse(int x){
    return power(x,mod-2,mod);
}

int const N = 1e5+5;
int const inf = 1e18;


void solve(){
    int i,j,l;
    int n;
    int m;
    cin>>n>>m;
    if(m>=n) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}   

int32_t main(){
    IOS;
    int t;
    t = 1;
    // pre();
    // cin>>t;
    for(int tt=1;tt<=t;tt++){
        solve();
    }
    return 0;
}

/*

*/