#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define vi vector < int >
#define pii pair < int, int >
#define INF (int)1e9
#define pb push_back
#define fastIO ios::sync_with_stdio(0); cin.tie(0);

string k;
int d, n;

int cache[10005][105][2];

int dpSol(int i, int rem, bool big_or_not)
{
    if(i == n)
    {
        if(rem == 0)
            return 1;
        return 0;
    }
    
    int &res = cache[i][rem][big_or_not];
    if(res != -1)
        return res;

    int maxnum = 9;
    if(big_or_not)
        maxnum = k[i] - '0';
        
    ll ans = 0;
    for(int j = 0; j <= maxnum; ++j)
    {
        int f = big_or_not;
        if(j < (k[i] - '0'))
            f = 0;
        ans = (ans + dpSol(i + 1, (rem + j) % d, f)) % MOD;
    }
    
    return res = ans;
}

int main()
{
    fastIO
    cin >> k;
    cin >> d;
    
    n = k.size();
    
    memset(cache, -1, sizeof(cache));
    cout << (dpSol(0, 0, 1) - 1 + MOD) % MOD;

    return 0;
}