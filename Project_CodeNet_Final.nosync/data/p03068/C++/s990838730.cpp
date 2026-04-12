#include <bits/stdc++.h>
#define REP(i, n) for (int i=0, i##_len=(n); i<i##_len; ++i)
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
using ll = long long;
using namespace std;

int main()
{
    int N, K;
    string S;
    cin >> N;
    cin >> S;
    cin >> K;
    --K;

    REP(i, N)
    {
        cout << (S[i] == S[K] ? S[K] : '*');
    }
    cout << endl;

    return 0;
}
