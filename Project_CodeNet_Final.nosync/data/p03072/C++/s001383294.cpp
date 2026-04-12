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
	ll n;
    cin >> n;
    vll h(n);
    ll tmp = 0, cnt = 0;
    REP(i, n){
        cin >> h[i];
        if(h[i] >= tmp){
            tmp = h[i];
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}