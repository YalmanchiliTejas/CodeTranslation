#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

const int MAXE { 3 }, MAXN { 110 }, MAXK { 4 };
const ll MOD { 1000000007 }, oo { 1LL << 62 };

ll st[MAXN][MAXE][MAXK];

ll solve(const string& s, int K)
{
    int N = s.size();
    vector<int> ds(N);

    for (int i = 0; i < N; ++i)
        ds[i] = (s[i] - '0');

    memset(st, 0, sizeof st);

    for (int d = 1; d < ds[0]; ++d)
        st[0][0][1]++;

    st[0][0][0] = 1;
    st[0][1][1] = 1;

    for (int i = 1; i < N; ++i)
    {
        st[i][0][0] = 1;

        for (int k = 1; k <= 3; ++k)
        {
//cout << "i = " << i << ", k = " << k << ", ds[" << i << "] = " << ds[i] << endl;
            st[i][0][k] = st[i - 1][0][k];
//cout << "1. st[" << i << "][" << 0 << "][" << k << "] = " << st[i][0][k] << endl;
            st[i][0][k] += 9*st[i - 1][0][k - 1];
//cout << "2. st[" << i << "][" << 0 << "][" << k << "] = " << st[i][0][k] << endl;

            st[i][0][k] += (ds[i] ? st[i - 1][1][k] : 0);
//cout << "3. st[" << i << "][" << 0 << "][" << k << "] = " << st[i][0][k] << endl;

            for (int d = 1; d < ds[i]; ++d)
                st[i][0][k] += st[i - 1][1][k - 1];

            st[i][1][k] += (ds[i] == 0 ? st[i - 1][1][k] : 0);
            st[i][1][k] += (ds[i] ? st[i - 1][1][k - 1] : 0);
        }
    }

#ifdef DEBUG
    for (int i = 0; i < N; ++i)
        for (int k = 0; k <= 3; ++k)
            for (int e = 0; e < 2; ++e)
                cout << "st[" << i << "][" << e << "][" << k << "] = " << st[i][e][k] << endl;
#endif

    ll ans = st[N - 1][0][K] + st[N - 1][1][K];

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    string N;
    int K;

    cin >> N >> K;

    auto ans = solve(N, K);

    cout << ans << '\n';

    return 0;
}
