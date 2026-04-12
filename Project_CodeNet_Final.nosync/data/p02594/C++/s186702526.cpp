#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
typedef unsigned long long int ull;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> o_set;

#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define     int                 ll
#define     xx                  first
#define     yy                  second    
#define     all(a)              a.begin(),a.end()
#define     vi                  vector<int>
#define     vpi                 vector<pii>
#define     pii                 pair<int, int>
#define     present(DT, val)    (DT.find(val) != DT.end()) //for set and map
#define     cpresent(DT, val)   (find(all(DT),val) != DT.end()) //vectors
#define     input               "/home/pollution/Desktop/WorkSpace/C++/Files/input.txt"
#define     output              "/home/pollution/Desktop/WorkSpace/C++/Files/output1.txt"
#define     error               "/home/pollution/Desktop/WorkSpace/C++/Files/error.txt"
#define     IO()                ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define     INF                 2e18
#define     MOD                 1000000007
#define     clr(x)              memset(x, 0, sizeof(x))
#define     out(a)              for (auto i: a) cout<<i<<' '; cout<<'\n'
#define     setd(val,n)         cout<<fixed<<setprecision(n)<<val<<'\n'

void solve(){
    int n;
    cin >> n;
    if(n >= 30){
    	cout << "Yes\n";
    }
    else{
    	cout << "No\n";
    }
}

signed main() { 
    
    
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0; 
}
