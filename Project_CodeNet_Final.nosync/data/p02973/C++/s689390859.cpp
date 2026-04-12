#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
 
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vll a(n);
    REP(i, n) cin >> a[i];
    vll x = {-a[0]};
    ll res = 1;
    REP(i, n){
        if(i == 0) continue;
        ll pos = upper_bound(ALL(x), -a[i]) - x.begin();
        if(pos == x.size()){
            x.push_back(-a[i]);
            res++;
        }
        else{
            x[pos] = -a[i];
        }
    }
    cout << res << endl;
    return 0;
}