#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define INIT(a,n,x); REP(i,(n)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define INIT2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"

#define umap unordered_map
//cout << setfill('0') << right << setw(4) << 12; // "0012"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}

// p1>p2<p3>p4...
// p1-p2 + p3 - p2 + p3 - p4
// +p1 + 2*p3 -2*p2 -p4

// p1<p2>p3<p4
// p2-p1 + p2-p3 + p4-p3
// -p1 - 2*p3 + 2*p2 + p4

// p1>p2<p3>p4<p5...
// p1-p2 + p3 - p2 + p3 - p4 + p5 - p4
// +p1 + 2*p3 + p5 -2*p2 -2*p4 

// p1<p2>p3<p4>p5
// -p1 - 2*p3 - p5 + 2*p2 + 2*p4


ll solve(){
  ll N; cin>>N;
  ll a[N]; CINA(a,N);
  sort(a,a+N,greater<int>());
  ll ans = 0;
  
  
  if(N%2==0){
    for(int i=0;i<=N/2-2;++i){ ans += a[i]*2;}
    ans += a[N/2-1];
    ans -= a[N/2];
    for(int i=N/2+1;i<N;++i){ ans -= a[i]*2; }
  }else{
    ll m1=0,m2=0;
    for(int i=0;i<=N/2-2;++i){ m1 += a[i]*2;}
    m1 += a[N/2-1];
    m1 += a[N/2];
    for(int i=N/2+1;i<N;++i){ m1 -= a[i]*2; }
    
    for(int i=0;i<N/2;++i){ m2 += a[i]*2;}
    m2 -= a[N/2];
    m2 -= a[N/2+1];
    for(int i=N/2+2;i<N;++i){ m2 -= a[i]*2; }
    
    ans = max(m1,m2);
  }
  return ans;
}

int main(){
  cout << solve()<<"\n";
}