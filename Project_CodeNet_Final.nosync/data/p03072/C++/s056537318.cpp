#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repR(i, n) for(int i = n; i >= 0; i--)
#define For(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;
using namespace std;
struct Fast {Fast(){std::cin.tie(0);std::ios::sync_with_stdio(false);}} fast;
template <class T = int> T in(){T x; cin >> x; return (x);}

int main(void){
    ll N;
    cin >> N;
    vector<ll> H;
    rep(i, N){
        ll x;
        cin >> x;
        H.push_back(x);
    }
    ll result = 1;
    
    ll max = H[0];
    For(i, 1, N){
        if(max <= H[i]){
            result ++;
            max = H[i];
        }
    }
    
    cout << result << endl;
    
    return 0;
}