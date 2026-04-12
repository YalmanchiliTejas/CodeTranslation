#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define repc(i, b, e) for(auto i = (b); i != (e); i++)

int main() {
    string S;
    ll N, K;
    cin >> N;
    cin >> S;
    cin >> K;
    repc(i, S.begin(), S.end()) {
        if(*i != S.at(K - 1)) {
            *i = '*';
        }
    }
    cout << S << endl;
    return 0;
}