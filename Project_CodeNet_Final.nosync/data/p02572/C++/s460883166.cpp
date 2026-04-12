#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;
#define rep(i, n)  for (int i = 0; i <  (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const ll INF = ll(1e18) + 1;
const ll mn = ll(1e9) + 7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> an(n);
    rep(i,n) cin >> an[i];

    ll result = 0;
    ll temp = 0;
    rep(i,n-1){
        temp += an[i];
        temp %= mn;
        result += temp * an[i+1] % mn;
        result %= mn;
    }
    cout << result;
}