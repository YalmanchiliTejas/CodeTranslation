#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const int INF = 1001001001;
const int MOD = 1000000007;

int main(){
    int N;
    cin >> N;

    vector<string> S(N);
    rep(i, N) cin >> S[i];

    map<char, int> mp;
    for (char c = 'a'; c <= 'z'; ++c) mp[c] = INF;
    for (char c = 'a'; c <= 'z'; ++c) {
        int res = INF;
        rep(i, N) {
            int cnt = 0;
            for (auto &j : S[i]) {
                if (c == j) cnt++;
            }
            res = min(res, cnt);
        }
        mp[c] = res;
    }

    for (auto &i : mp) {
        if (i.second != INF) {
            rep(j, i.second) cout << i.first;
        }
    }
    cout << endl;
}