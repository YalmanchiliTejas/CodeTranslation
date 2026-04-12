// In the Name of Allah. Ya Ali!
#include<bits/stdc++.h>
typedef long long ll;
const ll MAX_N = 2e5+100;
const ll MOD = 1e9+7;
using namespace std;

vector<int> l[MAX_N];
vector<int> r[MAX_N];
pair<int,int> lr[MAX_N];
ll dp[MAX_N];
ll mx[MAX_N*4];
ll fl[MAX_N*4];
ll a[MAX_N];
int n,m,y;

void update(int k)
{
    int l = k*2;
    int r = l+1;
    mx[k] = max(mx[l],mx[r]);
}

void shift(int k)
{
    int l = k*2;
    int r = l+1;
    fl[l]+=fl[k];
    fl[r]+=fl[k];
    mx[l]+=fl[k];
    mx[r]+=fl[k];
    fl[k] = 0;
}

void add(int l,int r,int a,int b,int k,ll d)
{
    if (r<a or b<l)
        return;
    if (a<=l and r<=b)
    {
        mx[k]+=d;
        fl[k]+=d;
        return;
    }
    int mid = (l+r)/2;
    shift(k);
    add(l,mid,a,b,k*2,d);
    add(mid+1,r,a,b,k*2+1,d);
    update(k);
}

ll ask(int l,int r,int a,int b,int k)
{
    if (r<a or b<l)
        return (-1e18);
    if (a<=l and r<=b)
        return mx[k];
    int mid = (l+r)/2;
    shift(k);
    return max(ask(l,mid,a,b,k*2),ask(mid+1,r,a,b,k*2+1));
}

int main()
{
    cin >> n >> m;
    for(int i = 1;i<=m;++i)
    {
        cin >> lr[i].first >> lr[i].second >> a[i];
        l[lr[i].first].push_back(i);
        r[lr[i].second].push_back(i);
    }
    y = (1<<((int)ceil(log2(n+10))));
    for(int i = 1;i<=n;++i)
    {
        ll sum = 0;
        for(auto x:l[i])
            sum+=a[x];
        dp[i] = ask(0,y-1,0,i-1,1)+sum;
        add(0,y-1,0,i-1,1,sum);
        add(0,y-1,i,i,1,dp[i]);
        for(auto x:r[i])
            add(0,y-1,0,lr[x].first-1,1,-a[x]);
    }
    ll ans = 0;
    for(int i = 1;i<=n;++i)
        ans = max(ans,dp[i]);
    cout << ans;
    return 0;
}
