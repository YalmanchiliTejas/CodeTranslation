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
typedef pair<ll,ll> pi;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

const ll OO = 1e18+7;
const int MOD = 1e9+7;
const int N = 2e5+7;

// vec[i] = ls of intervals with r = i
vector<pi> vec[N];
int n,m;
ll dp[N],st[N*4],lzy[N*4];

void push(int p,int l,int r)
{
    if (l==r)
    {
        st[p] += lzy[p];
        lzy[p] = 0;
        return;
    }
    lzy[p*2] += lzy[p];
    lzy[p*2+1] += lzy[p];
    //if (lzy[p] == -30) cout << l << ' ' << r<< st[p] << endl;
    st[p] += lzy[p];
    lzy[p] = 0;
    //cout << st[p] << endl;
}

void update(int i,int j,ll x,int p = 1,int l = 0,int r = n)
{
    push(p,l,r);
    if (i > r || j < l) return;
    if (l >= i && r <= j) {lzy[p] += x;push(p,l,r);return;}

    int mid = (l+r)/2;
    update(i,j,x,p*2,l,mid);
    update(i,j,x,p*2+1,mid+1,r);
    //cout << l << ' ' << r << endl;
    //cout << st[p*2] << ' ' << st[p*2+1] << endl;
    st[p] = min(st[p*2],st[p*2+1]);
}

ll query(int i,int j,int p = 1,int l = 0,int r = n)
{
    push(p,l,r);
    if (i > r || j < l) return 0;
    if (l >= i && r <= j) return st[p];

    int mid = (l+r)/2;
    ll ch1 = query(i,j,p*2,l,mid);
    ll ch2 = query(i,j,p*2+1,mid+1,r);
    return min(ch1,ch2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("teleport.in","r",stdin);
    //freopen("teleport.out","w",stdout);

    //REP(i,0,N*4 -1 ) st[i] = OO;

    cin >> n >> m;
    ll sum = 0;
    REP(i,0,m-1)
    {
        int l,r,a;
        cin >> l >> r >> a;
        sum += a;
        vec[r].PB({l,a});
    }

    // dp[i][j] = min of values we dont trigger if last 1 is j
    ll ans = 0;
    ll best = 0;
    REP(i,1,n)
    {
        dp[i] = query(0,i-1);
        update(i,i,dp[i]);
        for(auto p:vec[i])
        {
            int l = p.F;
            int a = p.S;
            //cout << l-1 << ' ' << a << endl;
            update(0,l-1,a);
            //cout << st[1] << endl;
        }
        //cout << dp[i] << endl;
    }

    ans = min(dp[n],st[1]);
    ans = min(ans,0LL);
    //cout << st[1] << endl;
    cout << sum-ans << endl;

    return 0;
}
