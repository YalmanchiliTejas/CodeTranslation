#include <bits/stdc++.h>
#define debug(x) cerr << "\n" \
                      << #x << " = " << x << ".\n"
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define print(xx) cout << (xx) << endl
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vint;
const int INF = ((1LL << 30) + (1LL << 29));
const ll MOD = 1000000007;

/* 

*/

//================== INPUT ========================
int N;
vector<int> A;
//=================================================
void input()
{
    cin >> N;
    A = vector<int>(N);
    rep(i, N)
    {
        cin >> A[i];
    }
}

//=================================================
void solve()
{
    deque<int> d; // double-ended-queue
    rep(i, N)
    {
        int p = lower_bound(d.begin(), d.end(), A[i]) - d.begin(); // index
        if (p == 0)
        {
            d.push_front(A[i]);
        }
        else
        {
            d[p - 1] = A[i];
        }
    }
    cout << d.size() << endl;
}

//=================================================
signed main()
{
    input();
    solve();
    return 0;
}