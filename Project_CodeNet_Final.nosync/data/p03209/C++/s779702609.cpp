#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, uint>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 3;

ll rec(ll n, ll x) {
    if (n == 0) return 1;
    ll len = (1LL << (n+1)) - 3;
    ll num = (1LL << n) - 1;

    if (x == 1) return 0;
    else if (x <= len + 1) return rec(n-1, x-1);
    else if (x == len + 2) return num + 1;
    else if (x <= (len + 1) * 2) return num + 1 + rec(n-1, x-len-2);
    else return num * 2 + 1;
}

void solve(){
    ll N, X; cin >> N >> X;
    cout << rec(N, X) << endl;
    return;
}

int main() {
    #ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt"};
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

