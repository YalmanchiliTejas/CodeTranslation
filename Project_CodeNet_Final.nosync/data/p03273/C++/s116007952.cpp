#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<typename T> inline bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<typename T> inline bool chmin(T &a,T b){if(b<a){a=b;return 1;}return 0;}
template<typename T> vector<T> make_vec(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>
auto make_vec(size_t a,Ts... ts){return vector<decltype(make_vec<T>(ts...))>(a,make_vec<T>(ts...));}
template<typename T,typename U,typename... V>
typename enable_if<is_same<T,U>::value>::type fill_v(U &u,const V... v){u=U(v...);}
template<typename T,typename U,typename... V>
typename enable_if<!is_same<T,U>::value>::type fill_v(U &u,const V... v){for(auto &e:u)fill_v<T>(e,v...);}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;
    auto a = make_vec<char>(h, w);
    rep(i, h) rep(j, w) cin >> a[i][j];

    set<int> rmi, rmj;
    rep(i, h) {
        bool flag = true;
        rep(j, w) if (a[i][j] == '#') flag = false;
        if (flag) rmi.insert(i);
    }
    rep(j, w) {
        bool flag = true;
        rep(i, h) if (a[i][j] == '#') flag = false;
        if (flag) rmj.insert(j);
    }
    rep(i, h) {
        if (rmi.count(i)) continue;
        rep(j, w) {
            if (rmj.count(j)) continue;
            cout << a[i][j];
        }
        cout << endl;
    }
        
}
