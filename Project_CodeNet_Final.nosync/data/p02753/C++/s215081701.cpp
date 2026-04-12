#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;

typedef long long ll;
// const int INF = 1e8;
const ll INF = 1LL << 60;
typedef pair<int, int> P;

string S;

int main() {
    cin >> S;
    if (S[0] == 'A' && S[1] == 'A' && S[2] == 'A') {
        cout << "No" << endl;
        return 0;
    }
    if (S[0] == 'B' && S[1] == 'B' && S[2] == 'B') {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
}