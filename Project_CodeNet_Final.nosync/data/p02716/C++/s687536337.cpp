#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;
const ll inf = 1e15;

const ll MAXN = 200*1000+5;
ll a[MAXN];
map<pair<ll,ll>,ll> memo; 

ll dp(ll idx, ll need){
    if (need==0) return 0;
    if (idx<0) return -inf;
    if (need > (idx+1)/2+1) return -inf;
    pair<ll,ll> state{idx,need};
    
    if (memo.count(state)) return memo[state]; 
    return memo[state] = max(dp(idx-1,need), dp(idx-2,need-1)+a[idx]);
}


int main(){
	
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    ll n;cin>>n;
    REP(i,n) cin>>a[i];
    cout<< dp(n-1,n/2) <<endl;
    return 0;
}