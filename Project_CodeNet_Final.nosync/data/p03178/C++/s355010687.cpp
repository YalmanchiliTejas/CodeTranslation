#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a; i<b; ++i)
#define FR(a, b) for(int i = a; i>=b;--i)
#define _upgrade cin.tie(0); ios_base::sync_with_stdio(0)
#define pb push_back
#define mp make_pair
#define INF 1e9+2137
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef double db;
typedef unsigned long long ull;
typedef pair<int, int> iPair;

const int MAX = 1e5+2;
const int M = 1e9+7;

string s;

int d;
ll dp[MAX][101][2];

ll solve(int pos, int rem, bool lo)
{
    if(dp[pos][rem][lo] != -1)
        return dp[pos][rem][lo];

    if(pos == s.size())
    {
        if(rem)
            return dp[pos][rem][lo] = 0;
        else
            return dp[pos][rem][lo] = 1;
    }
    ll res = 0, hi = s[pos]-'0';
    if(lo)
        hi = 9;

    for(int i = 0; i<= hi; ++i)
    {
        bool nl = lo;
        if(!lo && i < hi)
            nl = 1;
        res += solve(pos+1, (rem+i)%d, nl);
        res %= M;
    }
    return dp[pos][rem][lo] = res%M;
}

int main()
{
    _upgrade;
    cin>>s>>d;
    memset(dp, -1, sizeof dp);
    cout<<(solve(0, 0, 0)-1+M)%M;
}
