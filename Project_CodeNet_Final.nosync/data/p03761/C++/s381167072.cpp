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
    vec<int> ans(26);
    rep(i, n) {
        vec<int> mp(26);
        cin >> S[i];
        for(auto e:S[i]){
            ++mp[e-'a'];
        }
        if(i==0) ans = mp;
        else {
            rep(i,26){
                ans[i] = min(ans[i],mp[i]);
            }
        }
    }

    for(int i=0;i<26;++i){
        rep(_,ans[i]){
            cout << (char)('a'+i);
        }
    }
    cout << '\n';
}
