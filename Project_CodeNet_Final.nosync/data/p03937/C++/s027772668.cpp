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
bool IsPossible(int H, int W, const vector<string>& A)
{
    if (A[0][0] != '#') return false;
    if (A[H - 1][W - 1] != '#') return false;

    rep(r, 0, H)
    {
        rep(c, 0, W)
        {
            if (A[r][c] != '#') continue;

            int inNum = 0, outNum = 0;
            if (r > 0 && A[r - 1][c] == '#') ++inNum;
            if (c > 0 && A[r][c - 1] == '#') ++inNum;
            if (r < H - 1 && A[r + 1][c] == '#') ++outNum;
            if (c < W - 1 && A[r][c + 1] == '#') ++outNum;

            if (r == 0 && c == 0)
            {
                if (outNum != 1) return false;
            }
            else if (r == H - 1 && c == W - 1)
            {
                if (inNum != 1) return false;
            }
            else
            {
                if (inNum != 1 || outNum != 1) return false;
            }
        }
    }

    return true;
}

void _main()
{
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    rep(r, 0, H) cin >> A[r];
    cout << (IsPossible(H, W, A) ? "Possible" : "Impossible") << endl;
}
