#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vb=vector<bool>;
using vvb=vector<vb>;
using vc=vector<char>;
using vvc=vector<vc>;
using pii = pair<int,int>;
using pil = pair<int,ll>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

ll power(ll a, int b) {
  if(!b) return 1;
  ll c = power(a, b/2);
  if(b%2) return c*c%INF*a%INF;
  return c*c%INF;
}

int main() {
  int N;
  cin >> N;
  vi A(N);
  rep(i,N) cin >> A[i];
  ll ss=0,s=0;
  rep(i,N) {
    (ss+=(ll)A[i]*A[i])%=INF;
    (s+=(ll)A[i])%=INF;
  }
  
  cout << (s*s-ss+INF)%INF*power(2,INF-2)%INF << endl;
}