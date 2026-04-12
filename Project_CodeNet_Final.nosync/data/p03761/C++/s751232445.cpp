#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define PI acos(-1)

int main() {
    int N;
    cin >> N;
    vector<vector<int>> cnt(N, vector<int>(26));
    Rep(i, N) {
        string S;
        cin >> S;
        Rep(j, S.size()) {
            cnt[i][S[j] - 'a']++;
        }
    }
    string ans = "";
    Rep(i, 26) {
        int count = 10000;
        Rep(j, N) {
            count = min(count, cnt[j][i]);
        }
        Rep(j, count) {
            ans += 'a' + i;
        }
    }
    cout << ans << endl;
    return 0;
}