#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>
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
#define chu(x)  if(DEBUG_Switch) cout<<"["<<#x<<" "<<(x)<<"]"<<endl
#define du3(a,b,c) scanf("%d %d %d",&(a),&(b),&(c))
#define du2(a,b) scanf("%d %d",&(a),&(b))
#define du1(a) scanf("%d",&(a));
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll powmod(ll a, ll b, ll MOD) { if (a == 0ll) {return 0ll;} a %= MOD; ll ans = 1; while (b) {if (b & 1) {ans = ans * a % MOD;} a = a * a % MOD; b >>= 1;} return ans;}
ll poww(ll a, ll b) { if (a == 0ll) {return 0ll;} ll ans = 1; while (b) {if (b & 1) {ans = ans * a ;} a = a * a ; b >>= 1;} return ans;}
void Pv(const vector<int> &V) {int Len = sz(V); for (int i = 0; i < Len; ++i) {printf("%d", V[i] ); if (i != Len - 1) {printf(" ");} else {printf("\n");}}}
void Pvl(const vector<ll> &V) {int Len = sz(V); for (int i = 0; i < Len; ++i) {printf("%lld", V[i] ); if (i != Len - 1) {printf(" ");} else {printf("\n");}}}
inline long long readll() {long long tmp = 0, fh = 1; char c = getchar(); while (c < '0' || c > '9') {if (c == '-') fh = -1; c = getchar();} while (c >= '0' && c <= '9') tmp = tmp * 10 + c - 48, c = getchar(); return tmp * fh;}
inline int readint() {int tmp = 0, fh = 1; char c = getchar(); while (c < '0' || c > '9') {if (c == '-') fh = -1; c = getchar();} while (c >= '0' && c <= '9') tmp = tmp * 10 + c - 48, c = getchar(); return tmp * fh;}
void pvarr_int(int *arr, int n, int strat = 1) {if (strat == 0) {n--;} repd(i, strat, n) {printf("%d%c", arr[i], i == n ? '\n' : ' ');}}
void pvarr_LL(ll *arr, int n, int strat = 1) {if (strat == 0) {n--;} repd(i, strat, n) {printf("%lld%c", arr[i], i == n ? '\n' : ' ');}}
const int maxn = 1000010;
const int inf = 0x3f3f3f3f;
/*** TEMPLATE CODE * * STARTS HERE ***/
#define DEBUG_Switch 0
int main()
{
#if DEBUG_Switch
    freopen("C:\\code\\input.txt", "r", stdin);
#endif
    //freopen("C:\\code\\output.txt","w",stdout);
    int x;
    cin >> x;
    if (x >= 30)
    {
        printf("Yes\n");
    } else
    {
        printf("No\n");
    }
    return 0;
}


