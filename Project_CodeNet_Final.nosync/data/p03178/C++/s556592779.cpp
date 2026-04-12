#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
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
#define rrep(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define tr(it,c) for(iter(c) it=(c).begin();it!=(c).end();it++)
template<Z A>void pr(A a){cout<<a;ln;}
template<Z A,Z B>void pr(A a,B b){cout<<a<<' ';pr(b);}
template<Z A,Z B,Z C>void pr(A a,B b,C c){cout<<a<<' ';pr(b,c);}
template<Z A,Z B,Z C,Z D>void pr(A a,B b,C c,D d){cout<<a<<' ';pr(b,c,d);}
template<Z A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}ln;}
ll check(ll n,ll m,ll x,ll y){return x>=0&&x<n&&y>=0&&y<m;}
const ll MAX=1e9+7,MAXL=1LL<<61,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
typedef pair<int,int> P;

void Main() {
  string s;
  ll m;
  cin >> s >> m;
  ll n=s.size();
  ll d[n+1][m];
  mem(d);
  d[0][0]=1;
  rep(i,n) {
    rep(j,m) {
      rep(k,10) {
        d[i+1][(j+k)%m]+=d[i][j];
        d[i+1][(j+k)%m]%=MAX;
      }
    }
  }
  ll ans=0,c=0;
  rep(i,n) {
    rep(j,s[i]-'0') {
      ans+=d[n-1-i][(m-(c+j)%m)%m];
      ans%=MAX;
    }
    c+=s[i]-'0';
    c%=MAX;
  }
  if(c%m==0) {
    ans++;
    ans%=MAX;
  }
  pr((ans-1+MAX)%MAX);
}

int main(){ios::sync_with_stdio(0);cin.tie(0);Main();return 0;}
