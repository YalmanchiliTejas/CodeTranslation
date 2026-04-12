#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define up_b upper_bound
#define low_b lower_bound
#define sz(x) (int)x.size()
#define all(v) v.begin(),v.end()

#define boost ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;

const ll INF=1e18;
const ll inf = 1e9;
const ld eps=1e-7;
const ld pi = acos(-1);
const int dx[4]={0,0 ,1,-1};
const int dy[4]={1,-1,0,0};
const int N=1e5+11;
const int M=803;
const int mod=998244353;

int a[N];
int t[4*N];

void upd(int v,int tl,int tr,int pos,int val){
  if(tl==tr){
    t[v]=max(t[v],val);
    return;
  }
  int tm=(tl+tr)/2;
  if(pos<=tm)upd(v*2,tl,tm,pos,val);
  else upd(v*2+1,tm+1,tr,pos,val);
  t[v]=max(t[v*2],t[v*2+1]);
}

int get(int v,int tl,int tr,int l,int r){
  if(tl>r||l>tr)return 0;
  if(l<=tl&&tr<=r)return t[v];
  int tm=(tl+tr)/2;
  return max(get(v*2,tl,tm,l,r),get(v*2+1,tm+1,tr,l,r));
}

int main(){
  int n;
  cin>>n;
  vector<pii>v;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    v.pb(mp(a[i],i));
  }
  sort(all(v));
  int cur=1;
  a[v[0].y]=cur;
  for(int i=1;i<n;i++){
    if(v[i].x!=v[i-1].x)cur++;
    a[v[i].y]=cur;
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    int val=get(1,1,cur,a[i],cur)+1;
    ans=max(ans,val);
    upd(1,1,cur,a[i],val);
  }
  cout<<ans;
  return 0;
}
