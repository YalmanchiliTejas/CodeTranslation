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

vector<ll> len;

ll rec(int level, ll x) {
    if (level == 0) return 1;
    if (x <= 1) return 0;
    else if (x <= 1 + len[level-1]) return rec(level-1, x-1);
    else if (x <= 1 + len[level-1] + 1) return rec(level-1, len[level-1]) + 1;
    else if (x <= 1 + len[level-1] + 1 + len[level-1]) return rec(level-1, len[level-1]) + 1 + rec(level-1, x-(1+len[level-1]+1));
    else return 2 * rec(level-1, len[level-1]) + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; ll x;
    cin >> n >> x;
    len.resize(51);
    len[0] = 1;
    for (int i = 1; i <= 50; ++i) {
        len[i] = 3 + 2*len[i-1];
    }
    cout << rec(n, x) << endl;
}
