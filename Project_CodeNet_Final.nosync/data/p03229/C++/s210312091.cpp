#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
ll Solve(const vector<ll>& A, bool fromFront)
{
    const int N = A.size();
    vector<ll> B(N * 2, -1);
    int aFront, aBack;
    if (fromFront)
    {
        B[N] = A[0];
        aFront = 1;
        aBack = N - 1;
    }
    else
    {
        B[N] = A[N - 1];
        aFront = 0;
        aBack = N - 2;
    }

    int bLeft = N;
    int bRight = N;

    rep(i, 0, N - 1)
    {
        const bool isBack = (i / 2) % 2 == (fromFront ? 0 : 1);

        // Left
        if (i % 2 == 0)
        {
            --bLeft;
            if (isBack) B[bLeft] = A[aBack--];
            else B[bLeft] = A[aFront++];
        }
        // Right
        else
        {
            ++bRight;
            if (isBack) B[bRight] = A[aBack--];
            else B[bRight] = A[aFront++];
        }
    }

    ll sum = 0;
    rep(i, bLeft, bRight)
    {
        sum += abs(B[i + 1] - B[i]);
    }

    return sum;
}

void _main()
{
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];
    sort(A.begin(), A.end());

    const ll a = Solve(A, true);
    const ll b = Solve(A, false);
    cout << max(a, b) << endl;
}
