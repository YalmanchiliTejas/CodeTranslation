#include <bits/stdc++.h>
#define va first
#define vb second
#define lb lower_bound
#define pb push_back
#define all(v) v.begin(),v.end()
#define fio ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using lf = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

ll D[3005][3005];
bool v[3005][3005];
ll a[3005];
int n;

ll dp(int s, int e){
    if(s > e) return 0;
    ll &d = D[s][e];
    if(v[s][e]) return d;
    v[s][e] = 1;
    int turn = (n - e + s) & 1;
    if(turn){ //First
        return d = max(dp(s+1,e)+a[s],dp(s,e-1)+a[e]);
    }else{ //Second
        return d = min(dp(s+1,e)-a[s],dp(s,e-1)-a[e]);
    }
}

int main(){
    fio;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cout << dp(1,n) << '\n';
}