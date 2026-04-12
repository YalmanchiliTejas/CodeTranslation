#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define ll long long
#define pi pair<int,int>
#define pl pair<ll,ll>
#define pd pair<double,double>
#define ld long double
#define pld pair<ld,ld>
#define lg length()
#define sz size()
#define pb push_back
#define INF 1000000005
#define LINF 1000000000000000005

int n,m;

struct seg{
    int l,r,v;
} a[200005];

ll dp[200005],s[200005],sg[800005],lz[800005],f[200005],ans;

bool comp(seg a, seg b){
    return a.r<b.r;
}

void Sift(int nod, int l, int r){
    sg[nod]+=lz[nod];
    if(l!=r){
        lz[2*nod]+=lz[nod];
        lz[2*nod+1]+=lz[nod];
    }
    lz[nod]=0;
}

void Upd(int lt, int rt, ll v, int nod=1, int l=1, int r=n){
    Sift(nod,l,r);
    if(l>rt || r<lt) return;
    if(l>=lt && r<=rt){
        lz[nod]+=v;
        Sift(nod,l,r);
        return;
    }
    int mid=(l+r)/2;
    Upd(lt,rt,v,2*nod,l,mid);
    Upd(lt,rt,v,2*nod+1,mid+1,r);
    sg[nod]=max(sg[2*nod],sg[2*nod+1]);
}

int32_t main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> a[i].l >> a[i].r >> a[i].v;
        f[a[i].l]+=a[i].v;
        f[a[i].r+1]-=a[i].v;
    }
    for(int i=1;i<=n;i++){
        f[i]+=f[i-1];
    }
    sort(a+1,a+m+1,comp);
    int j=1;
    for(int i=1;i<=n;i++){
        Sift(1,1,n);
        dp[i]=f[i]+sg[1];
        Upd(i,i,dp[i]-f[i]);
        while(j<=m && a[j].r==i){
            Upd(a[j].l,a[j].r,a[j].v);
            j++;
        }
        ans=max(ans,dp[i]);
    }
    cout << ans;
}
