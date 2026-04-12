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

const int maxn = 3e3+5;
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

ll a[maxn];
ll dp[maxn][maxn][2];

ll solve(ll l, ll r, int person)
{
    if(l > r)               return 0;
    if(dp[l][r][person])    return dp[l][r][person];
    int nxt = (person + 1) % 2;
    if(person == 0) dp[l][r][person] = max(solve(l + 1, r, nxt) + a[l], solve(l, r - 1, nxt) + a[r]);
    if(person == 1) dp[l][r][person] = min(solve(l + 1, r, nxt) - a[l], solve(l, r - 1, nxt) - a[r]);
    return dp[l][r][person];
}

int main()
{
    //ios::sync_with_stdio(false);
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);

    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    ll answer = solve(1, n, 0);

    printf("%lld\n", answer);


    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}
