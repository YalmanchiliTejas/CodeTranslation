#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, begin, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int N;
    cin >> N;
    vector<int> H(N);
    int ans = 0;
    rep(i, 0, N)
    {
        cin >> H.at(i);
    }
    bool f;
    rep(i, 0, N)
    {
        f = true;
        rep(j, 0, i)
        {
            if (H.at(j) > H.at(i))
            {
                f = false;
                break;
            }
        }
        if (f)
        {
            ans++;
        }
    }
    cout << ans << endl;
}