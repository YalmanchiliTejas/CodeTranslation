#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define PB push_back
#define REP(i,a,b) for (int i = a ; i <= b ; i++)
#define REPI(i,a,b) for (int i = a ; i >= b ; i--)
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

const ll OO = 1e18+7;
const int MOD = 1e9+7;
const int N = 3e3+7;
int n;
ll mem[2][N][N];
ll a[N];

ll dp(bool p,int l,int r)
{
    ll &ret = mem[p][l][r];
    if (ret != -1) return ret;
    if (l > r) return 0;
    if (!p)
    {
        ret = max(dp(!p,l+1,r)+a[l],dp(!p,l,r-1)+a[r]);
    }
    else
    {
        ret = min(dp(!p,l+1,r)-a[l],dp(!p,l,r-1)-a[r]);
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("teleport.in","r",stdin);
    //freopen("teleport.out","w",stdout);
    memset(mem,-1,sizeof mem);
    cin >> n;
    REP(i,0,n-1) cin >> a[i];

    cout << dp(0,0,n-1) << endl;

    return 0;
}
