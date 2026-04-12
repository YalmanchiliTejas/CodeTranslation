#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

const int MAX_N = 50;
const int INF = 1E+04;

int N;

string S[MAX_N];
int alb[26];
int tmpalb[26];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    fill(alb, alb + 26, INF);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < S[i].size(); j++) {
            tmpalb[S[i][j] - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            alb[j] = min(alb[j], tmpalb[j]);
        }
        memset(tmpalb, 0, sizeof(tmpalb));
    }

    string ans = "";

    for (int i = 0; i < 26; i++) {
        ans += string(alb[i], 'a' + i);
    }

    cout
        << ans << "\n";

    return 0;
}