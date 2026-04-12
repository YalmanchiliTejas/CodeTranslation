#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
template<class T> bool chmin(T& a,T b){if(a>b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a,T b){if(a<b) {a = b; return true;} return false;}
#define all(x) (x).begin(),(x).end()
#define debug(x)  cerr << #x << " = " << (x) << endl;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,X,M;
    cin >> N >> X >> M;
    if(X==0){
        cout << 0 << "\n";
        return 0;
    }
    int K = 40;
    vvec<ll> f(K+1,vec<ll>(M)),val = f;
    for(ll i=0;i<M;i++){
        ll ne = i*i%M;
        f[0][i] = ne;
        val[0][i] = ne;
    }

    for(int k=0;k<K;k++){
        for(int i=0;i<M;i++){
            f[k+1][i] = f[k][f[k][i]];
            val[k+1][i] = val[k][i]+val[k][f[k][i]];
        }
    }
    ll ans = X;
    ll now = N-1;
    int pos = X;
    for(int k=K;k>=0;k--){
        if(now>>k&1){
            ans += val[k][pos];
            pos = f[k][pos];
        }
    }
    cout << ans << "\n";
}