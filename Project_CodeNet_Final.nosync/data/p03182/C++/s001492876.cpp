#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
#define pb push_back
#define mp make_pair
#define fr(i,n) for(int i=0;i<n;i++)
#define Fr(i,n) for(int i=0;i++<n;)
#define ifr(i,n) for(int i=n-1;i>=0;i--)
#define iFr(i,n) for(int i=n;i>0;i--)

vector<P> lar[200010]={};

ll dat[800010],del[800010],n;

void init(ll n_){
  n=1;
  while(n<n_) n*=2;
  fr(i,2*n-1) dat[i]=0;
}

void ud(ll be,ll en,ll c,ll k=0,ll l=0,ll r=n){
  if(r<=be||en<=l) return;
  if(be<=l&&r<=en){del[k]+=c;return;}
  ud(be,en,c,k*2+1,l,(l+r)/2);
  ud(be,en,c,k*2+2,(l+r)/2,r);
  dat[k]=max(dat[k*2+1]+del[k*2+1],dat[k*2+2]+del[k*2+2]);
}

ll mx(ll be,ll en,ll k=0,ll l=0,ll r=n){
  if(be==en) return 0;
  if(r<=be||en<=l) return 0;
  if(be<=l&&r<=en) return del[k]+dat[k];
  del[k*2+1]+=del[k];del[k*2+2]+=del[k];dat[k]+=del[k];del[k]=0;
  return max(mx(be,en,k*2+1,l,(l+r)/2),mx(be,en,k*2+2,(l+r)/2,r))+del[k];
}

int main(){
  ll N,m,l,r,a;
  cin>>N>>m;
  init(N+1);
  fr(i,m){cin>>l>>r>>a;lar[r].pb(mp(l,a));}
  Fr(i,N){
    ud(i,i+1,mx(0,i));
    for(auto it=lar[i].begin();it!=lar[i].end();it++){
      ud((*it).first,i+1,(*it).second);
    }
  }
   cout<<mx(0,N+1)<<endl;
}