#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define rrep(i,n) for(int i=(int)n-1;i>=0;--i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
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
    int x = n * 800;
    int y = n / 15 * 200;
    cout << x - y << endl;
}
