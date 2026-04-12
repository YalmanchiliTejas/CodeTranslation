#include <bits/stdc++.h>

#define int         long long
#define uint        unsigned int
#define ld          long double
#define showoff     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb          push_back
#define pii         pair<int,int>
#define FOR(i,a,b)  for(int i=a;i<b;++i)
#define RFOR(i,a,b) for(int i=a;i>b;--i)
#define f           first
#define se          second
#define maxn        200005
#define all(v)      v.begin(),v.end()
#define sz(x)       (int)x.size()
#define mod         1000000007
#define pqueue      priority_queue<int>
#define pdqueue     priority_queue< pii,vector<pii> ,greater< pii >>

using namespace std;


//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*int power(int a,int n)
{
    if(n == 1)return a%mod;
    if(n == 0)return 1;
    if(n&1)return ((a%mod)*(power((a*a)%mod,n/2))%mod)%mod;
    return power((a*a)%mod,n/2)%mod;
}*/
//const int md = 998244353;

/*int inverse(int x){

    return power(x,mod-2)%mod;//little fermat....
}*/
const int inf = (int) 1e18;
const int md = (int) 1e9+21;


signed main()
{
    showoff;
    int n;
    cin >> n;
    int ans = 0,ma = 0,h[n+5];
    FOR(i,1,n+1){
        cin >> h[i];
        if(h[i] >= ma)++ans;
        ma = max(ma,h[i]);
    }
    cout << ans;
    return 0;
}
//*->for large size of matrix take int not long long if possible......
//*->always take maximum as inf for safer side ...
