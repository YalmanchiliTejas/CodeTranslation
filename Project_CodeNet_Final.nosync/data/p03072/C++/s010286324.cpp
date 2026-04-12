#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define Cout(s) cout << s << endl;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1ll << 60;
ll MOD = 1e9 + 7;

int main()
{

    int n;
    cin >> n;
    vector<int> h(n);

    int mh = 0;
    int cnt = 0;
    REP(i, n)
    {
        int now;
        cin >> now;
        h[i] = now;
        if (mh <= now)
        {
            mh = now;
            cnt++;
        }
    }
    Cout(cnt);
    return 0;
}