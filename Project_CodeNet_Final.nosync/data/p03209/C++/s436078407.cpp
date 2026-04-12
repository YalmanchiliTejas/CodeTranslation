#include <bits/stdc++.h>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;

ll N, X;
ll len[55];
ll pat[55];

ll rec(ll n, ll x) {
  if(x==0) return 0;
  if(n==0) return 1;
  
  if(x<=1+len[n-1])
    return rec(n-1, x-1);
  else
    return pat[n-1]+1+rec(n-1, x-1-len[n-1]-1);
  
}

int main(void) {
  cin >> N >> X;
  ll i, j;
  
  len[0]=1;
  pat[0]=1;
  for(i=1; i<=N; i++) {
    len[i]=1+len[i-1]+1+len[i-1]+1;
    pat[i]=pat[i-1]+1+pat[i-1];
  }
  
  pt(rec(N, X));
  
}
