#include <bits/stdc++.h>
#define ft first
#define sc second
#define pt(sth) cout << sth << "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
template<class T>bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;

//for(i=0; i<N; i++) cin >> a[i];

ll mxl[MAX*2][2]={}; //mxl[i][0]: 最後にi-1を選択, mxl[i][1]: 最後にiを選択
ll mxr[MAX*2][2]={}; //mxr[i][0]: 最後にiを選択, mxr[i][1]: 最後にi+1を選択

int main(void) {
  ll i, j, k;
  
  ll N;
  ll a[MAX*2];
  
  cin >> N;
  for(i=1; i<=N; i++) cin >> a[i];
  
  for(i=2; i<=N; i+=2) {
    mxl[i][0]=mxl[i-2][0]+a[i-1];
    mxl[i][1]=max(mxl[i-2][0], mxl[i-2][1])+a[i];
  }
  
  for(i=N-1; i>=2; i-=2) {
    mxr[i][0]=max(mxr[i+2][0], mxr[i+2][1])+a[i];
    mxr[i][1]=mxr[i+2][1]+a[i+1];
  }
  
  if(!(N&1)) {
    pt(max(mxl[N][0], mxl[N][1]));
    return 0;
  }
  
  
  ll os[MAX*2]={};
  ll es[MAX*2]={};
  for(i=1; i<=N; i++) {
    if(i&1) {
      os[i]=os[i-1]+a[i];
      es[i]=es[i-1];
    }else {
      os[i]=os[i-1];
      es[i]=es[i-1]+a[i];
    }
  }
  
  ll ans=-INF;
  for(i=1; i<N-1; i+=2) {
    ll t= max(mxl[i-1][0], mxl[i-1][1]) + os[N]-os[i];
    chmax(ans, t);
  }
  
  for(i=2; i<N; i+=2) {
    ll t=os[i-1]+ max(mxr[i+2][0], mxr[i+2][1]);
    chmax(ans, t);
  }
  
  ll c=0;
  for(i=2; i<N; i+=2) c+=a[i];
  chmax(ans, c);
  
  pt(ans);
}
 
 


