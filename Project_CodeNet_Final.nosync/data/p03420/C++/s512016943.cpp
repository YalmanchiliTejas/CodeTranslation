#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
 
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    if(k == 0){
        cout << n * n << endl;
        return 0;
    }

    ll res = 0, tmp;
    for(int i = k + 1; i <= n; i++){
        if(n % i >= k) tmp = n % i - k + 1;
        else tmp = i - k;
        res += ((n - k) / i) * (i - k) + tmp;
    }
    cout << res << endl;
    return 0;
}