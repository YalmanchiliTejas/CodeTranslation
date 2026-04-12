#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define all(v) v.begin(),v.end()
#define res(n) resize(n)
#define rev(v) reverse(v.begin(),v.end())
#define so(v) sort(v.begin(),v.end())
#define outve(v) for(auto i : v) cout << i << " ";cout << endl
#define in(n,v) for(int i=0; i<(n); i++){cin >> v[i];}
#define out(n) cout << (n) << endl
#define fi first
#define se second
#define ve vector
#define pa pair
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<ll,ll>> vpl;
typedef vector<vector<pair<int,int>>> vvp;




int main()
{
    int N;cin>>N;
    vi a(N);in(N,a);
    int inf = 1000000009;
    vi dp(N,inf);
    rev(a);
    rep(i,N){
        auto k = upper_bound(all(dp),a[i]) - dp.begin();
        if(k < N) dp[k] = a[i];
    }
    cout << lower_bound(all(dp),inf)-dp.begin()<< endl;

    
   
    
    
    
    return 0;
}

