#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS (1e-7)
#define INF (1e9)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const double PI = acos(-1);
const ll MOD = 1000000007;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
///////////////////////////////////////////////////////////////

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); //入出力高速化
  while (true) {
    int N; cin >> N;
    if (N == 0) break;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    sort(all(A));
    ll sum = accumulate(A.begin()+1,A.end()-1,0);
    cout << sum / (N-2) << endl;
  }
}
