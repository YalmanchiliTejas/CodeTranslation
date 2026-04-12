#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#define start_routine() int begtime = clock();
#define end_routine() int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0
#define speed() cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
// #define exit(a, b) return cout << a, b;
 
// debugger
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#define debug(stuff) cout << #stuff << ": " << stuff <<endl
#define debugc(stuff) cout << #stuff << ": "; for(auto x: stuff) cout << x << " "; cout << endl;
// 
 
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define all(v) v.begin(), v.end() 
 
#define print(stuff) cout << stuff << endl
#define printc(stuff) for(auto x: stuff) cout << x << " "; cout << endl;
#define printPrec(stuff) cout << fixed << setprecision(15) << stuff << endl;
#define len length
#define ret0 return 0
#define ret return 
 
 
#define ll long long
#define ld long double
#define fi first
#define endl '\n'
#define se second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fill(ar, x) memset(ar, x, sizeof ar)
 
#define vl vector<ll> 
#define sl set<ll>
#define pll pair<ll, ll>
#define mll map<ll, ll> 
#define pq priority_queue<ll>
 
// typedef tree<ll,null_type,less<ll>,rb_tree_tag,
// tree_order_statistics_node_update> indexed_set;
 
#define inf (long long int) 1e18
#define eps 0.000001
#define mod 1000000007
#define mod1 998244353
#define MAXN (ll)2e5+5
#define N (1ll<<10)

ll n;
ll a[MAXN];
ll dp[MAXN][2];

ll f(ll idx, bool extra){
    // trace(idx);
    if(idx == n-1){
        if(extra == 0) return dp[idx][extra] = 0;
        else return dp[idx][extra] = a[idx];
    }
    if(idx >= n){
        return 0;
    } 
    else if(dp[idx][extra] != -1) return dp[idx][extra];  
    else {
        if((n-idx)%2 == 0){
            assert(extra == 0);
            if(extra == 1) return dp[idx][extra] = 0;
            else{
                // ll ans = a[idx] + f(idx+2,0);
                ll ans = max(a[idx] + f(idx+2, 0), f(idx+1, 1));
                return dp[idx][extra] = ans;
            } 
        }
        else {
            if(extra == 1){
                return dp[idx][extra] = a[idx] + f(idx+2, 1);
            }
            else return dp[idx][extra] = max(f(idx+1, 0), a[idx] + f(idx+2, 0));
        }
    }
}

void solve(){
    loop(i,0,MAXN) loop(j,0,2) dp[i][j]  =-1;
    cin>>n;
    loop(i, 0, n) cin>>a[i];
    print(f(0, 0));
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        start_routine();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
 
    ll t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
        
    #ifndef ONLINE_JUDGE
        end_routine();
    #endif
}
