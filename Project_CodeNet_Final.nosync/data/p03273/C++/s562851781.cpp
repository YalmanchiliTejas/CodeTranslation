#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define debug(x) cerr << #x << " = " << x << "\n"
#define debugv(x) rep(i, x.size()) cerr << x[i] << (i == x.size() - 1 ? "\n" : " ")
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int, int> pii;
const int INF = ((1LL << 30) + (1LL << 29));
const int MOD = 1000000007;

//=============================
int N, M, K;
int H, W;
string S, T;
vector<string> A;
//=============================
void input()
{
    cin >> H >> W;
    A.resize(H);
    rep(i, H)
    {
        cin >> A[i];
    }
}
//=============================
void func() {}
//=============================
void solve()
{
    vector<bool> h(H);
    vector<bool> w(W);

    rep(i,H){
        bool f = false;
        rep(j,W){
            if (A[i][j] == '#'){
                f = true;
                break;
            }
        }
        h[i] = f;
    }
    rep(j,W){
        bool f = false;
        rep(i,H){
            if (A[i][j] == '#'){
                f = true;
                break;
            }
        }
        w[j] = f;
    }

    rep(i,H){
        if (!h[i])continue;
        rep(j,W){
            if (!w[j])continue;
            cout<<A[i][j];
        }
        cout<<endl;
    }

}
//=============================
signed main()
{
    input();
    solve();
    return 0;
}