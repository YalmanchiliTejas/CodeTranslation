#include <bits/stdc++.h>

#define PI 3.1415926535897932
#define MOD 1000000007
#define INF 1e9

#define REP(i, n) for(int i = 0; i < (n); i++)
#define REP1(i, n) for(int i = 1; i <= (n); i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;


void solve()
{
    int H, W; cin >> H >> W;
    vector<vector<char>> grid(H, vector<char>(W)); REP(i, H) REP(j, W) cin >> grid[i][j];

    // 行成分を取り除く
    int i = 0;
    while(i < grid.size())
    {
        bool isAllWhite = true;
        REP(j, W)
        {
            if(grid[i][j] == '#')
            {
                isAllWhite = false;
                break;
            }
        }
        if(isAllWhite)
        {
            grid.erase(grid.begin()+i);
        }
        else i++;
    }

    H = grid.size();
    vector<vector<char>> ans(W, vector<char>(H));
    REP(i, H) REP(j, W) ans[j][i] = grid[i][j];

    i = 0;
    while(i < ans.size())
    {
        bool isAllWhite = true;
        REP(j, H)
        {
            if(ans[i][j] == '#') 
            {
                isAllWhite = false;
                break;
            }
        }
        if(isAllWhite)
        {
            ans.erase(ans.begin()+i);
        }
        else i++;
    }

    W = ans.size();

    REP(i, H)
    {
        REP(j, W)
        {
            cout << ans[j][i];
        }
        cout << endl;
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}