// Wed Jul 29 19:48:22 IST 2020    
#include <bits/stdc++.h>        
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define forn(ii,a,b)        for(int ii = (int)a ; ii < (int)b  ; ii++ )
#define debug(x)           cerr << #x << " " << x << " -- \n"
#define I__O               ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define int64              long long   
#define all(x)             (x).begin(),(x).end() 
#define precise(x)         cout << fixed << setprecision(12) << x << '\n'; 
using namespace std ;    
// policy based   
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set ; 
 
const int MOD = 1e9+7;
const double pi = 3.141592653589793238;
const int N = 2e5+7; 
const int INF = INT_MAX;

vector <vector <int>> g;
vector <int> people,happy,sum;
int n,m;
int dfs(int node,int parent){
    sum[node] = people[node];
    for(auto & child : g[node])
        if(child != parent)
            sum[node] += dfs(child,node); 
    return sum[node];
}
vector <int> bad,good;
bool check (int node, int parent, int bound){
    
    int childs_good = 0;
    bool ok = good[node] <= sum[node];
    for(auto &child : g[node])
        if(child != parent)    
            childs_good += good[child];
    ok &= childs_good <= good[node];
    return ok;
}
int tests(){ 
    int X;
    cin >> X;
    cout << (X >= 30 ? "Yes": "No") << '\n';
    return 0;
}   
int32_t main(){
    I__O ;     
    int cases = 1 ;  
    // cin >> cases ;
    for(int test = 1 ; test <= cases ; ++test){ 
        // cout << "Case #" << test << ":" << '\n';
        tests();
    }    
    return 0 ; 
}
