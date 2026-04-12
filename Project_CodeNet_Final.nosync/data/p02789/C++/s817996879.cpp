#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<list>
#include<cmath>
#include<algorithm>
#define lson node<<1,st,mid
#define rson node<<1|1,mid+1,ed
#define mem(a,x) memset(a,x,sizeof(a))
#define me(a) memset(a,0,sizeof(a))
#define IOS ios::sync_with_stdio(false)
#define lowbit(x) x&(-x)
#define up(i,x,y) for(long long i=x;i<y;i++)
#define down(i,x,y) for(long long i=x;i>=y;i--)
#define in freopen("in.txt","r",stdin)
#define out freopen("out.txt","w",stdout)  	
typedef long long ll;
const ll mod = 1e9 + 7;
const ll INF = 0x3f3f3f3f;
const int maxn = 1e6+5;
const double pi = acos(-1.0);
using namespace std;
ll qpow(ll a, ll b) { ll s = 1; while (b > 0) { if (b & 1)s = s * a % mod; a = a * a % mod; b >>= 1; }return s; }
ll read()     //输入外挂
{
    ll res = 0, ch, flag = 0;
    if ((ch = getchar()) == '-')
        flag = 1;
    else if (ch >= '0' && ch <= '9')
        res = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9')
        res = res * 10 + ch - '0';
    return flag ? -res : res;
}
int main() {
    ll n, m;
    cin >> n >> m;
    if (n == m) cout << "Yes" << endl;
    else cout << "No" << endl;
}