#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<long long> buns_num(51);
vector<long long> paty_num(51);

long long buns(int N, long long X)
{
    if (N == 0)
    {
        return 1;
    }

    long long ans = 0;
    if (X == 1)
    {
        return ans;
    }
    else if (X <= buns_num[N - 1] + 1)
    {
        X -= 1;
        ans += buns(N - 1, X);
        return ans;
    }
    else if (X == buns_num[N - 1] + 2)
    {
        ans += paty_num[N - 1] + 1;
        return ans;
    }
    else if (X <= 2 * buns_num[N - 1] + 2)
    {
        ans += paty_num[N - 1] + 1;
        X -= buns_num[N - 1] + 2;
        ans += buns(N - 1, X);
        return ans;
    }
    else if (X == 2 * buns_num[N - 1] + 3)
    {
        ans += 2 * paty_num[N - 1] + 1;
        return ans;
    }

    cout << "error" << endl;
    return -1;
}

int main()
{
    buns_num[0] = 1;
    paty_num[0] = 1;
    rep(i, 50)
    {
        buns_num[i + 1] = 3 + 2 * buns_num[i];
        paty_num[i + 1] = 1 + 2 * paty_num[i];
    }

    long long N, X;
    cin >> N >> X;

    long long ans = buns(N, X);
    cout << ans << endl;
    return 0;
}