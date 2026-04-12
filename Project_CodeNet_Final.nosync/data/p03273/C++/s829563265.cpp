/**
 *
 * AtCoder Beginner Contest 107 - Problem A: Train (https://beta.atcoder.jp/contests/abc107/tasks/abc107_a)
 *
 * Find the index j of the element i, if the vector is read backwards.
 *
 * Math solution: j = N - i + 1.
 */
#include <iostream>

#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <bitset>
#include <cstring>
#include <algorithm>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

#define LOG(var, sep) (cerr << #var << " = " << (var) << (sep))
#define LOGM(msg) (cerr << (msg))
#define LOGV(vec, sep) { cerr << #vec << " ="; for (const auto& v : (vec)) cerr << " " << v; cerr << (sep); }
#define LOGA(arr, N, sep) { cerr << #arr << " ="; for (int i = 0; i < N; ++i) cerr << " " << (arr)[i]; cerr << (sep); }
#define LOGA2(arr, N, M, sep) { cerr << #arr << " =\n"; for (int i = 0; i < N; ++i) { for (int j = 0; j < M; ++j) cerr << (arr)[i][j] << " "; cerr << endl; } cerr << (sep); }

#define REP(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)

ostream& operator<<(ostream& os, const ii& p)
{
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

const int MAX { 2000010 };

string as[MAX];

void solve(int H, int W)
{
    set<int> cs, rs;

    REP(i, 0, H - 1)
    {
        auto sum = 0;

        REP(j, 0, W - 1)
        {
            sum += (as[i][j] == '#' ? 1 : 0);
        }

        if (sum == 0)
        {
            rs.insert(i);
        }
    }

    REP(j, 0, W - 1)
    {
        auto sum = 0;

        REP(i, 0, H - 1)
            sum += (as[i][j] == '#' ? 1 : 0);

        if (sum == 0)
        {
            cs.insert(j);
        }
    }

    REP(i, 0, H - 1)
    {
        bool printed = false;
        REP(j, 0, W - 1)
            if (rs.count(i) == 0 and cs.count(j) == 0)
            {
                printed = true;
                cout << (char) as[i][j];
            }

        if (printed)
            cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;

    REP(i, 0, H - 1)
        cin >> as[i];

    solve(H, W);

    return 0;
}
