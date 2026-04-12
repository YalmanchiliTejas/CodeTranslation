#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pi M_PI
#define R cin>>
#define Z class
#define ll long long
#define ln cout<<'\n'
#define in(a) insert(a)
#define pb(a) push_back(a)
#define pd(a) printf("%.10f\n",a)
#define mem(a) memset(a,0,sizeof(a))
#define all(c) (c).begin(),(c).end()
#define iter(c) __typeof((c).begin())
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define tr(it,c) for(iter(c) it=(c).begin();it!=(c).end();it++)
template<Z A>void pr(A a){cout<<a;ln;}
template<Z A,Z B>void pr(A a,B b){cout<<a<<' ';pr(b);}
template<Z A,Z B,Z C>void pr(A a,B b,C c){cout<<a<<' ';pr(b,c);}
template<Z A,Z B,Z C,Z D>void pr(A a,B b,C c,D d){cout<<a<<' ';pr(b,c,d);}
template<Z A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}ln;}
ll check(ll n,ll m,ll x,ll y){return x>=0&&x<n&&y>=0&&y<m;}
const ll MAX=1000000007,MAXL=1LL<<61,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
typedef pair<ll,ll> P;
typedef pair<P,ll> P2;
typedef pair<ll,P> PP;
int p[100001],r[100001];
void init(){rep(i,100001)p[i]=i,r[i]=0;}
int find(int x){return (p[x]==x)?x:(p[x]=find(p[x]));}
void unite(int x,int y) {
  x=find(x),y=find(y);
  if(x==y)return;
  if(r[x]<r[y])p[x]=y;
  else{p[y]=x;if(r[x]==r[y])r[x]++;}
}
bool same(int x,int y){return find(x)==find(y);}

void Main() {
  init();
  ll n;
  R n;
  vector<P> b(n);
  rep(i,n) cin >> b[i].F >> b[i].S;
  sort(all(b));
  b.erase(unique(all(b)),b.end());
  n=b.size();
  vector<P2> a(n);
  rep(i,n) a[i]=P2(b[i],i);
  sort(all(a));
  ll ans=0;
  priority_queue<PP,vector<PP>,greater<PP> > que;
  rep(k,2) {
    rep(i,n-1) que.push(PP(abs(a[i].F.F-a[i+1].F.F),P(a[i].S,a[i+1].S)));
    rep(i,n) swap(a[i].F.F,a[i].F.S);
    sort(all(a));
  }
  while(!que.empty()) {
    PP p=que.top();que.pop();
    int x=p.S.F,y=p.S.S;
    if(same(x,y)) continue;
    unite(x,y);
    ans+=p.F;
  }
  pr(ans);
}

int main(){ios::sync_with_stdio(0);cin.tie(0);Main();return 0;}
