#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define ms(s,x) memset(s,x,sizeof(s))
#define pb push_back
#define inf 0x3f3f3f3f
typedef long long ll;
using namespace std;

const int MAXN = 1e5+5;
const ll MOD = 1e9+7;

ll comb(int m, int n)
{
    ll up = 1, down = 1;
    rep(i, m-n+1, m)
    up *= i;
    rep(i, 1, n)
    down *= i;
    return up/down;
}

int main()
{
    string n;
    int k;
    ll ans;
    cin >> n >> k;
    int len = n.size();
    ans = pow(9, k)*comb(len-1, k);
    if (k == 1)
        ans += n[0]-'0';
    else if (k == 2)
    {
        ans += (n[0]-'1')*comb(len-1, 1)*9;
        rep(i, 1, len-1)
        {
            bool flag = 0;
            rep(j, 1, i-1)
                if (n[j] != '0')
                    flag = 1;
            if (flag)
                ans += 9;
            else
                ans += n[i]-'0';
        }
    }
    else
    {
        ans += (n[0]-'1')*comb(len-1, 2)*9*9;
        rep(i, 1, len-2)
        {
            bool f1 = 1;
            rep(j, 1, i-1)
                if (n[j] != '0')
                    f1 = 0;
            if (f1)
            {
                if (n[i] != '0')
                {
                    ans += (n[i]-'1')*comb(len-i-1, 1)*9;
                    rep(j, i+1, len-1)
                    {
                        bool f2 = 0;
                        rep(k, i+1, j-1)
                            if (n[k] != '0')
                                f2 = 1;
                        if (f2)
                            ans += 9;
                        else
                            ans += n[j]-'0';
                    }
                }
            }
            else
                ans += 9*comb(len-i-1, 1)*9;
        }
    }
    cout << ans << endl;

    return 0;
}
