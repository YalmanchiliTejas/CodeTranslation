#include<bits/stdc++.h>
using namespace std;

using ll = long long;
template <class T>
using V = vector<T>;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)

int main(){
    int N;
    cin >> N;
    V<int> A(N);
    rep(i, N) cin >> A.at(i);
    V<ll> rui(N);
    const ll m = 1000000007;
    rui.at(N - 1) = A.at(N - 1);
    per(i, N - 1) rui.at(i) = (rui.at(i+1) + A.at(i)) % m;
    ll sum = 0;
    rep(i, N-1){
        sum += A.at(i) * rui.at(i+1) % m;
        sum %= m;
    }
    cout << sum << endl;
}