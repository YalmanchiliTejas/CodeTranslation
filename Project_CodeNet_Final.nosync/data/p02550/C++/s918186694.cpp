#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    vector<ll> sum(m+10, 0), a(m+10, 0), move(1);
    a[1] = x;
    sum[1] = x;
    move.push_back(a[1]);
    map<ll, ll> check;
    check[a[1]]++;
    ll s, e;
    for (ll i=2; i<m+10; i++){
        a[i] = (a[i-1]*a[i-1])%m;
        sum[i] = sum[i-1] + a[i];
        if (i==n){
            cout << sum[i] << endl;
            return 0;
        }
        if (a[i]==0){
            cout << sum[i] << endl;
            return 0;
        }
        if (check[a[i]]>0){
            e = i - 1;
            for (ll j=1; j<(move.size()); j++) if (a[i]==move[j]){
                s = j - 1;
                break;
            }
            break;
        }
        check[a[i]] = 1;
        move.push_back(a[i]);
    }
    ll sho = (n - s) / (e - s);
    ll res = (n - s) % (e - s);
    ll ans = (sho)*(sum[e]-sum[s]) + sum[s+res];
    cout << ans << endl;
    //printf("%.12f", ans);
}