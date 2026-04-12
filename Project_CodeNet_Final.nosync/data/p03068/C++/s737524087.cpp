#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define repR(i, n) for(ll i = n; i >= 0; i--)
#define For(i, m, n) for(ll i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;
using namespace std;
struct Fast {Fast(){std::cin.tie(0);std::ios::sync_with_stdio(false);}} fast;

int main(void){
    string result = "No";
    ll N;
    string S;
    ll K;
    cin >> N >> S >> K;
    string s = S.substr(K-1, 1);
    rep(i, S.size()){
        if(S[i] != s[0]){
            S[i] = '*';
        }
    }
    
    
    cout << S << endl;
    return 0;
}
