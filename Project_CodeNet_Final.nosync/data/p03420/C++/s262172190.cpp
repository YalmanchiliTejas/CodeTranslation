#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, uint>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 3;

void solve(){
    ll N, K; cin >> N >> K;
    if(K == 0){
        cout << N * N << '\n';
        return;
    }

    ll ans = 0;
    for(ll i = K; i < N+1; ++i) {
            ans += N / i * (i - K);
            ans += max(0LL, (N % i) - K + 1LL);
    }
    cout << ans << '\n';
    return;
}



int main() {
    #ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt"};
    cout << "------------\n";
    for(int i = 0; i < CASES; ++i){
        ifstream in(filenames[i]);
        cin.rdbuf(in.rdbuf());
        solve();
        cout << "------------\n";
    }
    #else

    solve();

    #endif
    return 0;
}

