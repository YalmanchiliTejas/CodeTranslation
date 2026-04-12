#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <queue>
#include <deque>
#include <stack>
#include <time.h>
#include <stdlib.h>
#include <bitset>
#include <algorithm>

#include <chrono>

#define INF 1e9
#define LL_INF 1e18

#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((int)(x.size()))

#define MOD1 998244353
#define MOD2 666013
#define P1 255
#define P2 2059

using namespace std;

typedef long long int ll;

typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define nmax 3010

int n;
int a[nmax];
bool fr[nmax][nmax];
ll dp[nmax][nmax];

ll compute(int l, int r)
{
    if (l > r) return 0;
    if (fr[l][r]) return dp[l][r];

    fr[l][r] = true;

    ll l_ans = a[l] - compute(l + 1, r);
    ll r_ans = a[r] - compute(l, r - 1);

    return dp[l][r] = max(l_ans, r_ans);
}

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    printf("%lld", compute(1, n));

    // IMPORTANT!!!!!
    // Are you missing something????
    // check limits, int or ll

    return 0;
}