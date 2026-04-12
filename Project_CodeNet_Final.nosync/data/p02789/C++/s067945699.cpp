#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef unsigned long long int ull;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> o_set; 

#define     int                 ll
#define     pb                  push_back
#define     mp                  make_pair
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
#define     init(x, a)          memset(x, a, sizeof(x))
#define     out(a)              for (auto i: a) cout<<i<<' '; cout<<'\n'
#define     cpy(a,b)            memcpy(a,b,sizeof(b))
#define     is(a)               to_string(a)
#define     ci(a,c)             a-c
#define     debug(i)            cout<<"point :"<<i<<'\n';
#define     setd(val,n)         cout<<fixed<<setprecision(n)<<val<<'\n'


void solve(){
    int n,m;cin>>n>>m;
    cout<<(n>m?"No\n":"Yes\n");
}

signed main() { 
    IO();

    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0; 
} 
