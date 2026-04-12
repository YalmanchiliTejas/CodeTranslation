#include<bits/stdc++.h>

using namespace std;

int N, a[109], dp[109][109][3];
const int mod = 1e9 + 7;
long long e2 = 0;

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

int power (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = mul (p, a);
        a = mul (a, a);
    }
    return p;
}

int p2 (long long e) {return power (2, e % (mod - 1));}

void solve (int i, int j, int lastH)
{
    int minH = a[i], maxH = a[i];
    for (int k=i; k<=j; k++)
        minH = min (minH, a[k]),
        maxH = max (maxH, a[k]);
    if (minH == maxH)
    {
        int h = minH - lastH + 1;
        dp[i][j][0] = dp[i][j][1] = p2 (h - 1);
        if (j - i + 1 > 1) dp[i][j][2] = subtract (p2 (j - i + 1), 2);
        else dp[i][j][2] = 0;
        return ;
    }
    vector < pair < int, int > > v;
    int dp2[4];
    dp2[1] = dp2[2] = dp2[3] = 0;
    dp2[0] = 1;
    for (int l=i; l<=j; l++)
        if (a[l] > minH)
        {
            int r = l;
            while (r < j && a[r + 1] > minH)
                r ++;
            v.push_back ({l, r});
            solve (l, r, minH);
            int oldDp[4];
            memcpy (oldDp, dp2, sizeof (dp2));
            memset (dp2, 0, sizeof (dp2));
            for (int k1=0; k1<4; k1++)
            {
                int dp3[4];
                dp3[0] = 0;
                dp3[3] = dp[l][r][2];
                dp3[1] = dp[l][r][1];
                dp3[2] = dp[l][r][0];
                for (int k2=1; k2<4; k2++)
                {
                    int realK = 0;
                    if (l % 2 == i % 2) realK = k2;
                    else
                    {
                        if (k2 & 1) realK |= 2;
                        if (k2 & 2) realK |= 1;
                    }
                    adto (dp2[k1 | realK], mul (oldDp[k1], dp3[k2]));
                }
            }
            l = r;
        }
        else
        {
            int oldDp[4];
            memcpy (oldDp, dp2, sizeof (dp2));
            memset (dp2, 0, sizeof (dp2));
            for (int p=0; p<2; p++)
            {
                int o = 0;
                if (p != (l - i) % 2) o |= 1;
                else o |= 2;
                for (int k=0; k<4; k++)
                    adto (dp2[k | o], oldDp[k]);
            }
        }
    dp[i][j][0] = dp[i][j][1] = 1;
    dp[i][j][2] = dp2[3];
    for (auto s : v)
        for (int k=0; k<2; k++)
            dp[i][j][k] = mul (dp[i][j][k], dp[s.first][s.second][k ^ (s.first % 2) ^ (i % 2)]);
    if (lastH < minH)
    {
        int steps = minH - lastH, s = add (dp[i][j][0], dp[i][j][1]);
        s = mul (s, p2 (steps - 1));
        dp[i][j][0] = dp[i][j][1] = s;
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
solve (1, N, 1);
printf ("%d\n", add (add (dp[1][N][0], dp[1][N][1]), dp[1][N][2]));
return 0;
}
