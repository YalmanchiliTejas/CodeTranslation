#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

const int MOD = 1000000007;

const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

int main()
{
    int N;
    cin >> N;
    vector<int> H(N);
    int cnt = 0;
    rep(i, N)
    {
        cin >> H.at(i);
        bool possible = true;
        rep2(j, 0, i)
        {
            if (H.at(j) > H.at(i)) {
                possible = false;
            }
        }
        if (possible) {
            cnt++;
        }
    }

    cout << cnt << endl;
}