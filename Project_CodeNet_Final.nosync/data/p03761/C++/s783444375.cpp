#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1001001001;
const int MOD = 1e9 + 7;

int main(){
    int N;
    cin >> N;

    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vector<int> cnt(27, INF);
    rep(i, N) {
        rep(j, 27) {
            cnt[j] = min(cnt[j], (int)count(S[i].begin(), S[i].end(), char('a' + j)));
        }
    }

    rep(i, 27) {
        rep(j, cnt[i]) cout << char('a' + i);
    }
    cout << endl;
}