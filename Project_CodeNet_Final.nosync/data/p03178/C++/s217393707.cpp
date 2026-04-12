#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll dp[10011][110][2];
int done[10011][110][2];
int cs;
string A;

ll k;

#define mod 1000000007

ll solve(int pos, int sum, bool small)
{
    if(pos == A.size())
    {
        if(sum == 0)
            return 1;
        else
            return 0;
    }

    if(done[pos][sum][small] == cs)
        return dp[pos][sum][small];

    ll ret = 0, i;
    if(small)
    {
        for(i = 0; i < 10; i++)
            ret = (ret + solve(pos + 1, (sum + i) % k, true))%mod;
    }
    else
    {
        for(i = 0; i < A[pos] - '0'; i++)
            ret = (ret + solve(pos + 1, (sum + i) % k, true))%mod;
        ret = (ret + solve(pos + 1, (sum + A[pos]-'0') % k, false))%mod;
    }

    done[pos][sum][small]=cs;
    return dp[pos][sum][small] = ret;
}

int main()
{
    //freopen("out.txt", "w", stdout);
    int test, i;
    ll low, high;
    for(int caseno = 1; cin >> A; caseno++)
    {
        cin >> k;
        cs++;
        high = solve(0, 0, 0) - 1;
        if (high < 0) high += mod;
        printf("%lld\n", high);
    }

    return 0;
}
