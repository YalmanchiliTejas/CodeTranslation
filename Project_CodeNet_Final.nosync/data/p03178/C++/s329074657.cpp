#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005;
const ll mod = 1000000007;
ll rtmp[MAXN];
ll r[MAXN];

int main()
{
    string s;
    int d;
    cin >> s >> d;

    int prsum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < d; j++)
        {
            rtmp[j] = 0;
            for (int dg = 0; dg <= 9; dg++)
                rtmp[j] += r[(j - (dg%d) + d) % d];
            rtmp[j] %= mod;
        }
        int digit = (int)(s[i] - '0');
        for (int dg = 0; dg < digit; dg++)
        {
            rtmp[(prsum + dg)%d]++;
            rtmp[(prsum + dg)%d] %= mod;
        }
        prsum += digit;
        swap(rtmp, r);
    }
    r[prsum%d]++;
    cout << (r[0] - 1 + mod) % mod;
    return 0;
}


