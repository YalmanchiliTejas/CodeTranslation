#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    vector<bool> col(H, false);
    vector<bool> row(W, false);
    rep(0, i, H)
    {
        cin >> S[i];
        rep(0, j, W)
        {
            if (S[i][j] == '#')
            {
                col[i] = true;
                row[j] = true;
            }
        }
    }
    int count;
    rep(0, i, H)
    {
        count = 0;
        rep(0, j, W)
        {
            if (col[i] && row[j])
            {
                cout << S[i][j];
                count++;
            }
        }
        if (count != 0)
        {
            cout << endl;
        }
    }
}