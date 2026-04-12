//include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <utility>
#include <string>
#include <set>
#include <map>
#include <cassert>
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pf push_front
#define pof push_front
#define pb push_back
#define pob pob_back
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FOR_(i, n) for (int i = n; i >= 0; i--)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
#define FOR2(i, a, b) for (int i = a; a <= b; i++)
#define FOR2_(i, b, a) for (int i = b; i >= a; i--)
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#ifdef momo
#define  debug(...) do{\
fprintf(stderr,"%s - %d : (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
_do(__VA_ARGS__);\
}while(0)
template<typename t> void _do(t &&_x){cerr<<_x<<endl;}
template<typename t,typename ...T> void _do(t &&_x,T &&...tail){cerr<<_x<<", ";_do(tail...);}
#else
#define debug(...)
#endif


const int MXN = 8 + 5;

int N, M;

vector<int> E[MXN];

bool vis[MXN];

int dfs(int now, int cnt) {
    //cout << now << '\n';
    vis[now] = true;
    if (cnt == N) {
        vis[now] = false;
        return 1;
    }
    int ans = 0;
    for (int i : E[now]) if (!vis[i])
        ans += dfs(i, cnt+1);
    vis[now] = false;
    return ans;
}

int main(void)
{
    IOS;
    
    cin >> N >> M;
    FOR(i, M) {
        int a, b; cin >> a >> b;
        E[a].pb(b), E[b].pb(a);
    }
    cout << dfs(1, 1) << endl;
    return 0;
}