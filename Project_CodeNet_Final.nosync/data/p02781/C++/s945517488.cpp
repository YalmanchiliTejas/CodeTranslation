#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#define ALL(x) (x).begin(), (x).end()
#define sz(a) int(a.size())
#define rep(i,x,n) for(int i=x;i<n;i++)
#define repd(i,x,n) for(int i=x;i<=n;i++)
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define gbtb ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MSC0(X) memset((X), '\0', sizeof((X)))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define eps 1e-6
#define chu(x) cout<<"["<<#x<<" "<<(x)<<"]"<<endl
#define du3(a,b,c) scanf("%d %d %d",&(a),&(b),&(c))
#define du2(a,b) scanf("%d %d",&(a),&(b))
#define du1(a) scanf("%d",&(a));
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll powmod(ll a, ll b, ll MOD) { if (a == 0ll) {return 0ll;} a %= MOD; ll ans = 1; while (b) {if (b & 1) {ans = ans * a % MOD;} a = a * a % MOD; b >>= 1;} return ans;}
void Pv(const vector<int> &V) {int Len = sz(V); for (int i = 0; i < Len; ++i) {printf("%d", V[i] ); if (i != Len - 1) {printf(" ");} else {printf("\n");}}}
void Pvl(const vector<ll> &V) {int Len = sz(V); for (int i = 0; i < Len; ++i) {printf("%lld", V[i] ); if (i != Len - 1) {printf(" ");} else {printf("\n");}}}
inline long long readll() {long long tmp = 0, fh = 1; char c = getchar(); while (c < '0' || c > '9') {if (c == '-') fh = -1; c = getchar();} while (c >= '0' && c <= '9') tmp = tmp * 10 + c - 48, c = getchar(); return tmp * fh;}
inline int readint() {int tmp = 0, fh = 1; char c = getchar(); while (c < '0' || c > '9') {if (c == '-') fh = -1; c = getchar();} while (c >= '0' && c <= '9') tmp = tmp * 10 + c - 48, c = getchar(); return tmp * fh;}
const int maxn = 10010;
const int inf = 0x3f3f3f3f;
/*** TEMPLATE CODE * * STARTS HERE ***/
char s[maxn];
int k;
ll dp[maxn][5];
int cnt;
ll dfs(int pos, int num, int limit)
{
    if (pos == cnt + 1)
    {
        return num == k;
    }
    if (!limit && dp[pos][num] != -1)
    {
        return dp[pos][num];
    }
    int up;
    if (limit)
    {
        up = s[pos] - '0';
    } else
    {
        up = 9;
    }
    ll res = 0ll;
    repd(i, 0, up)
    {
        if (i == 0)
        {
            res += dfs(pos + 1, num, limit && (i == up));
        } else
        {
            if (num + 1 <= k)
                res += dfs(pos + 1, num + 1, limit && (i == up));
        }
    }
    if (!limit)
    {
        dp[pos][num] = res;
    }
    // cout << pos << " " << num << " " << limit << " " << res << endl;
    return res;
}
int main()
{
    //freopen("D:\\code\\text\\input.txt","r",stdin);
    //freopen("D:\\code\\text\\output.txt","w",stdout);
    gbtb;
    cin >> s + 1;
    cin >> k;
    cnt = strlen(s + 1);
    memset(dp, -1, sizeof(dp));
    cout << dfs(1, 0, 1) << endl;
    return 0;
}


