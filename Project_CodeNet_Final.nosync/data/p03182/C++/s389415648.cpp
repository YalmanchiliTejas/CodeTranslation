#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define pi 3.1415926
using namespace std;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef pair<long long,int> pli;
typedef pair<int,long long> pil;
const ll INF=100000000000000007;
const int MOD=1000000007;
const int nmax=201234;

int n,m,l[nmax],r[nmax];
ll lt[nmax*4],lt2[nmax*4],a[nmax],dp[nmax],res;
vector<pii> v2,v3;

void pushdown(int i){
    lt2[i<<1]+=lt2[i];
    lt2[i<<1|1]+=lt2[i];
    lt2[i]=0;
}

void update(int i,int l,int r,int L,int R,ll val)
{
    if(l>R || r<L)
        return;
    else if(l>=L && r<=R)
        lt2[i]+=val;
    else
    {
        int mid=(l+r)>>1;
        pushdown(i);
        update(i<<1,l,mid,L,R,val);
        update(i<<1|1,mid+1,r,L,R,val);
        lt[i]=max(lt[i<<1]+lt2[i<<1],lt[i<<1|1]+lt2[i<<1|1]);
    }
}

ll query(int i,int l,int r,int pos)
{
    if(l>pos)
        return -INF;
    else if(r<=pos)
        return lt[i]+lt2[i];
    else{
        int mid=(l+r)>>1;
        pushdown(i);
        return max(query(i<<1,l,mid,pos),query(i<<1|1,mid+1,r,pos));
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; ++i)
    {
        scanf("%d%d%lld",&l[i],&r[i],&a[i]);
        v2.pb({l[i],i});
        v3.pb({r[i],i});
    }
    sort(v2.begin(),v2.end());
    sort(v3.begin(),v3.end());
    ll tmp=0;
    for(int i=1,j=0,k=0; i<=n; ++i)
    {
        while(j<m && v2[j].first<=i)
            tmp+=a[v2[j++].second];
        while(k<m && v3[k].first<i)
            tmp-=a[v3[k++].second];
        dp[i]=tmp;
    }
    tmp=0;
    for(int i=0; i<m; ++i)
        update(1,1,n,l[i],r[i],-a[i]);
    for(int i=1,k=0; i<=n; ++i)
    {
        dp[i]=dp[i]+max((ll)0,query(1,1,n,i-1));
        if(res<dp[i])
            res=dp[i];
        update(1,1,n,i,i,dp[i]);
        while(k<m && v3[k].first<=i){
            update(1,1,n,l[v3[k].second],v3[k].first,a[v3[k].second]);
            k++;
        }
    }        
    printf("%lld\n",res);
    return 0;
}
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
