#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <map>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
#define debug(x) cout <<#x<<" = "<<x<<endl
#define debug2(x, y) cout<<x<<" "<<y<<endl
#define gg cout <<"---------------QAQ---------------"<<endl
#define fi first
#define SZ(x) (int)x.size()
#define se second
#define pb push_back
#define inf 0x3f3f3f3f3f3f3f3f
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<pii, ll> Pii;
template<class T> inline void read(T &x){
    x=0; char c=getchar(); int f=1;
    while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
    while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 200005, maxn = 1666666;
void FAST(){ios::sync_with_stdio(false);cin.tie(0);}
const int mod = 3600;

int n, m;
ll sum[N], a[N], dp[N];

void solve()
{
    scanf("%d", &n);
    for(int i = 1;i <= n; ++i) {
        scanf("%lld", &a[i]);
        sum[i] = (i>=2?sum[i-2]:0)+a[i];
    }
    for(int i = 2; i <= n; ++i) {
        if(i&1) dp[i] = max(dp[i-2]+a[i], dp[i-1]);
        else dp[i] = max(dp[i-2]+a[i], sum[i-1]);
    }
    printf("%lld\n", dp[n]);
}


int main()
{

//    int _;scanf("%d", &_);while(_--)
//    while(~scanf("%d", &n))
    solve();
    return 0;
}
