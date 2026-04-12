#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

const int INF = 1 << 30;
const ll LLINF = 1LL << 62;

int mod = 1000000007;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S; cin >> S;
    if(S[0] == S[1] && S[1] == S[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}