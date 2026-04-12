#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n)-1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define loop while (true)

#define PB push_back
#define pb push_back
#define MP make_pair
#define mp make_pair
#define ALL(a) (a).begin(), (a).end()
#define all(a) (a).begin(), (a).end()

#define PII pair<int, int>
#define pii pair<int, int>
#define VB vector<bool>
#define VVB vector<vector<bool>>
#define VI vector<int>
#define VVI vector<vector<int>>

using namespace std;

typedef long long ll;
typedef unsigned long long ULL;

#define MAX 100001
bool ans[MAX];
bool kind[MAX];

bool check(bool a, bool b, int N)
{
    kind[0] = a;
    kind[1] = b;
    FOR(i, 2, N)
    {
        if (kind[i - 1]) {
            kind[i] = (ans[i - 1]) ? kind[i - 2] : (not kind[i - 2]);
        } else {
            kind[i] = (ans[i - 1]) ? (not kind[i - 2]) : kind[i - 2];
        }
    }
    if (kind[N - 1]) {
        bool f = (ans[N - 1] ? (kind[0] == kind[N - 2]) : (kind[0] != kind[N - 2]));
        if (f) {
            if (a) {
                return (ans[0]) ? (kind[1] == kind[N - 1]) : (kind[1] != kind[N - 1]);
            } else {
                return (ans[0]) ? (kind[1] != kind[N - 1]) : (kind[1] == kind[N - 1]);
            }
        } else {
            return f;
        }
    } else {
        bool f = (ans[N - 1] ? (kind[0] != kind[N - 2]) : (kind[0] == kind[N - 2]));
        if (f) {
            if (a) {
                return (ans[0]) ? (kind[1] == kind[N - 1]) : (kind[1] != kind[N - 1]);
            } else {
                return (ans[0]) ? (kind[1] != kind[N - 1]) : (kind[1] == kind[N - 1]);
            }
        } else {
            return f;
        }
    }
}

signed main()
{
    int N;
    cin >> N;
    char c;
    rep(i, N)
    {
        cin >> c;
        kind[i] = false;
        ans[i] = (c == 'o') ? true : false;
    }
    const bool flag = check(true, true, N) or check(true, false, N) or check(false, true, N) or check(false, false, N);
    if (flag) {
        rep(i, N)
        {
            cout << ((kind[i]) ? 'S' : 'W');
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }


    return 0;
}
