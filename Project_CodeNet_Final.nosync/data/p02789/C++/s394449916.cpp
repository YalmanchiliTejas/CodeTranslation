#include <bits/stdc++.h>
using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#define rep(i,a,n)    for(int i=a; i<=n; ++i)
#define rep1(i,a,n)   for(int i=a; i>=n; --i)
#define pb            push_back
#define mp            make_pair
#define int           long long
#define fr            first
#define sc            second
#define vc            vector
#define sz(v)         (int)v.size()
#define all(x)        (x).begin(),(x).end()
#define rall(x)       (x).rbegin(),(x).rend()
#define N             (int)(1e6+5)
#define M             1000000007
#define MM            998244353
#define PI            3.14159265358979
#define INF           1000000000000000

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef map<int,int> mii;

int n,m,ans; string str;


int solve(){
    cin>>n>>m;
    if(n==m) cout<<"Yes";
    else cout<<"No";    
    return 0;
}

signed main() {
    ios::sync_with_stdio(0);
    //std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
