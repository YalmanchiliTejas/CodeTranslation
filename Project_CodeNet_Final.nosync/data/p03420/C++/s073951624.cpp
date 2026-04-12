#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;

template<typename T> void print(const T & v);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, K;
    cin >> N >> K;

    if(K == 0){
        cout << N * N << endl;
        return 0;
    }

    ll ans = 0;
    for(ll b = 1; b <= N; b++){
        ll d = N / b;
        ans += d * max(0LL, b - K);
        if(N % b != 0){
            ans += max(0LL, N % b - K + 1);
        }
    }
    cout << ans << endl;
}


// Use For Debug
template <typename T>
void print(T const & v){
    for(int i = 0; i < v.size(); i++){
        if(i) cout << " ";
        cout << v[i];
    }
    cout << endl;
}
