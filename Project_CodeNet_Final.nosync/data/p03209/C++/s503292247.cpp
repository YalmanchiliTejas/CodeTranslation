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
vector<ll> layerNum;
vector<ll> pattiNum;
//------------------------------------------------------------------------------
ll Solve(int N, ll X)
{
    if (N == 0)
    {
        return X <= 0 ? 0 : 1;
    }
    else if (X <= 1 + layerNum[N - 1])
    {
        return Solve(N - 1, X - 1);
    }
    else
    {
        return pattiNum[N - 1] + 1 + Solve(N - 1, X - 2 - layerNum[N - 1]);
    }
}

void _main()
{
    int N;
    ll X;
    cin >> N >> X;

    layerNum.resize(N + 1);
    pattiNum.resize(N + 1);
    layerNum[0] = 1;
    pattiNum[0] = 1;
    rep(i, 0, N)
    {
        layerNum[i + 1] = layerNum[i] * 2 + 3;
        pattiNum[i + 1] = pattiNum[i] * 2 + 1;
    }

    cout << Solve(N, X) << endl;
}
