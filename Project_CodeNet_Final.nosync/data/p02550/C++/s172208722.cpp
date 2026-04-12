#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <cstdint>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000
#define MAX 200001

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const ll MOD = 998244353;

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

int main(){
    ll N, X, M;
    cin >> N >> X >> M;
    ll ans = 0;
    if(X == 0) cout << 0 << endl;
    else if(N <= M){
        rep(i,N){
            ans += X;
            X *= X;
            X %= M;
        }
        cout << ans << endl;
    }
    else{
        map<ll,ll> m;
        bool flag = false;
        ll cnt = M-1;
        m[X] = 1;
        rep(i,M-1){
            ans += X;
            X *= X;
            X %= M;
            if(m[X] > 0){
                N-=m[X]-1;
                cnt = i+1 - m[X] + 1;
                break;
            }
            m[X] = i+2;
            if(X == 0) flag = true;
        }
        if(flag) cout << ans << endl;
        else{
            ll original = X;
            ll res = 0;
            while(true){
                X *= X;
                X %= M;
                res += X;
                if(X == original) break;
            }
            ans -= res;
            ans += res * (N / cnt);
            N %= cnt;
            rep(i,N){
                ans += X;
                X *= X;
                X %= M;
            }
            cout << ans << endl;
        }
    }
}