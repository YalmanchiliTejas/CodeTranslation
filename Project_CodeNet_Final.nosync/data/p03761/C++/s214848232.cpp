#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int n;
    cin >> n;
    
    vec<string> S(n);
    map<char,int> ans;
    rep(i, n) {
        map<char,int> mp;
        cin >> S[i];
        sort(all(S[i]));
        for(auto e:S[i]){
            ++mp[e];
        }
        if(i==0) ans = mp;
        else {
            rep(i,26){
                ans['a'+i] = min(ans['a'+i],mp['a'+i]);
            }
        }
    }

    for(auto [f,s]:ans){
        rep(_,s){
            cout << f;
        }
    }
    cout << '\n';
}
