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
void _main()
{
    int N;
    ll X;
    cin >> N >> X;

    --X;

    vector<ll> layerNum(N + 1);
    vector<ll> pattiNum(N + 1);
    layerNum[0] = 1;
    pattiNum[0] = 1;

    rep(i, 0, N)
    {
        layerNum[i + 1] = layerNum[i] * 2 + 3;
        pattiNum[i + 1] = pattiNum[i] * 2 + 1;
    }

    // B BPPPB P BPPPB B
    // 0 12345 6 78901 2

    ll ans = 0;
    rrep(level, N, 0)
    {
        if (X == 0)
        {
            if (level == 0)
            {
                ++ans;
            }
            break;
        }
        else if (X == (layerNum[level] - 1) / 2)
        {
            ans += pattiNum[level - 1] + 1;
            break;
        }
        else if (X == layerNum[level] - 1)
        {
            ans += pattiNum[level];
            break;
        }
        else if (X < (layerNum[level] - 1) / 2)
        {
            --X;
        }
        else
        {
            X -= layerNum[level - 1] + 2;
            ans += pattiNum[level - 1] + 1;
        }
    }

    cout << ans << endl;
}
