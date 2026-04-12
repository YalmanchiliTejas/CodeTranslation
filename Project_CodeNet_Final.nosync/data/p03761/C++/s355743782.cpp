#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
const ll MOD = 1000000007;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    ll g = gcd(a, b);
    return a / g * b;
}

ll mulMod(ll a, ll b)
{
    return (((a % MOD) * (b % MOD)) % MOD);
}

void solve(long long n, std::vector<std::string> S)
{
    map<char, int> common;
    for (size_t i = 0; i < n; i++)
    {
        string str = S[i];
        for (char c = 'a'; c <= 'z'; c++)
        {
            int cnt = 0;
            for (unsigned int i = 0; i < str.size(); i++)
            {
                if (str[i] == c)
                    cnt++;
            }

            if (common.find(c) != common.end())
            {
                if (cnt < common[c])
                {
                    common[c] = cnt;
                }
            }
            else
            {
                common[c] = cnt;
            }
        }
    }

    for (auto itr = common.begin(); itr != common.end(); ++itr)
    {
        if (itr->second == 0)
        {
            continue;
        }
        else
        {
            for (int j = 0; j < itr->second; j++)
            {
                cout << itr->first;
            }
        }
    }
    cout << endl;
}

int main()
{
    long long n;
    scanf("%lld", &n);
    std::vector<std::string> S(n);
    for (int i = 0; i < n; i++)
    {
        cin >> S[i];
    }
    solve(n, std::move(S));
    return 0;
}
