#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define rrep(i,n) for(int i=(int)n-1;i>=0;--i)
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<typename T> inline bool chmin(T& a,T b){if(b<a){a=b;return 1;}return 0;}
template<typename T> vector<T> make_vec(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>
auto make_vec(size_t a,Ts... ts){return vector<decltype(make_vec<T>(ts...))>(a,make_vec<T>(ts...));}
template<typename T,typename U,typename... V>
typename enable_if<is_same<T,U>::value>::type fill_v(U& u,const V... v){u=U(v...);}
template<typename T,typename U,typename... V>
typename enable_if<!is_same<T,U>::value>::type fill_v(U& u,const V... v){for(auto& e:u)fill_v<T>(e,v...);}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> cnt(26);
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    rep(i, n) {
        if (i == 0) rep(j, s[i].size()) cnt[s[i][j] - 'a']++;
        else {
            vector<int> now(26);
            rep(j, s[i].size()) now[s[i][j] - 'a']++;
            rep(j, 26) chmin(cnt[j], now[j]);
        }
    }

    string ans;
    rep(i, 26) ans += string(cnt[i], 'a' + i);
    cout << ans << endl;
}
