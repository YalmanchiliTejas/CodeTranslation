// Vivek Rai
// Blazer_007

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>

#define fastio 		ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mp	     make_pair
#define inf         0x3f3f3f3f
//#define INF         0x3f3f3f3f3f3f3f3fLL
#define ll          long long
#define pb          push_back
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define vii         vector<pii>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define ppi	    pair<ll,pii>
#define all(a)      (a).begin(),(a).end()
#define FF           first
#define SS           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define see(x)	    cout<<x<<endl;
#define see2(x,y)   cout<<x<<" "<<y<<endl;
#define see3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define bit(x, y)   (((x)>>(y))&1)
#define bpt(x)      (__builtin_popcount(x))
#define bptl(x)     (__builtin_popcountll(x))
#define loop(i,a,b)  for(int i=a;i<b;i++)
#define rloop(i,a,b) for(int i=a;i>=b;i--)
#define N 2000010

using namespace std;
//using namespace __gnu_pbds;

//typedef priority_queue<int> maxHeap;
//typedef priority_queue<int,vector<int>,greater<int>()) minHeap;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order(index) -> value at given index or Kth smallest element in set
// order_of_key(X) -> number of elements strictly less than X
//typedef tree<pii , null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> OST;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif

ll dp[10001][101][2];

ll solve(string& k, int& D, int pos, int d, bool tight){
   if(dp[pos][d][tight] != -1)
        return dp[pos][d][tight] ;
   int ub = tight ? (k[pos] - '0') : 9 ;
   if(pos == k.length() - 1){
       ll ans2 = 0;
       loop(x,0,ub+1){
           if(x%D == d)
            ans2++;
       }
       return ans2;
   }
   ll ans = 0;
   loop(x,0,ub+1){
       ans = (ans + solve(k, D, pos+1, (D+d-x%D)%D, tight & (x == ub))) % hell ;
   }
   return dp[pos][d][tight] = ans;
}

void solution(){
    int D;
    string k;
    cin >> k;
    cin >> D;
    memset(dp,-1,sizeof dp);
    cout << (hell + solve(k, D, 0, 0, 1) - 1) % hell << endl;
}

signed main(){
    fastio
    // #ifndef ONLINE_JUDGE
    // 	freopen("input.txt", "r" , stdin);
    // 	freopen("output.txt", "w", stdout);
    // #endif

    ll t=1;
    // cin>>t;
    loop(i,1,t+1){
    	//cout<<"Case #"<<i<<": ";
    	solution();
    }
}


