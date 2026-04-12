#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vii> vvii;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forw(i,l,r) for(int i=(l);i<(r);i++)
#define forb(i,r,l) for(int i=(r);i>(l);i--)
#define log2i(x) 32 - __builtin_clz((x)) - 1
#define log2ll(x) 64 - __builtin_clzll((x)) - 1
#define Pi acos(-1.0)
#define sz(x) (int)x.size()
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int N = 3007;
const ll M = 998244353;
int n,s;
int a[N];
ll dp[N][3];

int main() {
#ifndef ONLINE_JUDGE
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
#endif
    fastIO;
    memset(dp,0,sizeof dp);
    dp[0][0]=1;
    cin >> n >> s;
    forw(i,0,n) cin >> a[i];
    forw(i,0,n) {
        forb(j,s-a[i],-1) {
            if(dp[j][0]) {
                dp[j+a[i]][0]=1;
                ll tmp=dp[j][1];
                if(j==0) tmp+=i+1;
                (dp[j+a[i]][1]+=tmp)%=M;
                (dp[j+a[i]][2]+=((n-i)*tmp)%M)%=M;
            }
        }
    }
    cout << dp[s][2];
    return 0;
}
