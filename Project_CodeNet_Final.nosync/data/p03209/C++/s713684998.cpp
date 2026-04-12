#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORL(i,x) for(int i=head[x];i;i=nxt[i])
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define PB push_back
#define MP make_pair
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


ll burger(ll n,ll x){
  if(n==0) return 1;
  ll len = (1LL<<(n+2)) - 3;
  ll pat = (1LL<<(n)) -1;


  // cout << "------------" << endl;
  // cout << n << " " << pat << endl;
  // cout << x << " " << len << endl;

  --x;

  if(x==0) return 0;
  else if(x <= len/2 - 1) return burger(n-1,x);
  else if(x == len/2) return pat + 1;
  else if(x <= len - 2) return pat + 1 + burger(n-1,x-len/2);
  else return pat * 2 + 1;

}


int main() {
  ll N,X;
  scanf("%lld%lld", &N,&X);

  cout << burger(N,X) << endl;

}

