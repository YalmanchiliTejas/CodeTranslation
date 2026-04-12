/*
    Written by Nitrogens
    Desire for getting accepted!!
*/
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <bitset>
#include <stack>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

const int maxn = 1e4+5;
const int Mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const double e = exp(1);
const db PI = acos(-1);
const db ERR = 1e-10;

#define Se second
#define Fi first
#define pb push_back
#define dbg(x) cout<<#x<<" = "<< (x)<< endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl

char input[maxn];
int digit[maxn];
ll dp[maxn][105];
int n, d;

ll dfs(int pos, bool limit, int sum)
{
    if(pos == n + 1)               return 1LL * (sum == 0);
    if(!limit && dp[pos][sum] != -1)    return dp[pos][sum];
    int range = limit ? digit[pos] : 9;
    ll res = 0;
    for(int i = 0; i <= range; i++)
    {
        res = (res + dfs(pos + 1, limit && i == digit[pos], (sum + i) % d)) % Mod;
    }
    if(!limit)  dp[pos][sum] = res;
    return res;
}

int main()
{
    //ios::sync_with_stdio(false);
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);

    scanf("%s", input + 1);
    scanf("%d", &d);

    n = strlen(input + 1);
    for(int i = 1; i <= n; i++) digit[i] = input[i] - '0';

    memset(dp, -1, sizeof(dp));
    ll answer = dfs(1, true, 0);

    printf("%lld\n", (answer - 1 + Mod) % Mod);

    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}
