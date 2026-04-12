#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 2147483647
#define double long double
#include <math.h>/* M_PI */
string s;
ll memo[105][10][2];
int done[105][10][2];
ll dp(int i, int j, int k) //indexでiまで決めた時に0以外をj個使って、k=0の時はNよりも小さいことが保証されている。k=1の時、Nと等しくなっている。
{
    if (done[i][j][k] == 1)
    {
        return memo[i][j][k];
    }
    ll res = 0;
    if (i == -1 && j == 0 && k == 1)
    {
        return 1;
    }
    else if (i == -1)
    {
        return 0;
    }
    else if (j == -1)
    {
        return 0;
    }
    if (k == 0)
    {

        res = dp(i - 1, j, 0) * 1 + dp(i - 1, j - 1, 0) * 9;
        //+dp(i - 1, j-1, 1)* dp(i - 1, j, 1)s[i]が0でなければ入る。
        if (s[i] != '0')
        {
            //cout << s[i] << endl;
            res += dp(i - 1, j, 1) + (s[i] - '0' - 1) * dp(i - 1, j - 1, 1);
        }
    }
    else //Nと等しいよって時
    {
        if (s[i] == '0')
        {
            res += dp(i - 1, j, 1);
        }
        else
        {
            res = dp(i - 1, j - 1, 1);
        }
    }
    memo[i][j][k] = res;
    done[i][j][k] = 1;
    return res;
}

int main()
{
    cin >> s;
    ll n = s.size();
    int k;
    cin >> k;

    cout << dp(n - 1, k, 0) + dp(n - 1, k, 1);
    //cout << dp(5, 2, 0); //1,1だけ使ってnより小さいことが確定
}
