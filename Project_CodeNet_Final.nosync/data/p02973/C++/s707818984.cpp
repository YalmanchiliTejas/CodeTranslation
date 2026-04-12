#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vb=vector<bool>;
using vvb=vector<vb>;
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int main() {
  int N;
  cin >> N;
  vi A(N);
  rep(i,N) cin >> A[i];
  
  vi count(N,-INF);
  rep(i,N) {
    int x=lower_bound(count.begin(),count.end(),A[i])-count.begin();
    count[x-1]=A[i];
  }
  int ans=0;
  rep(i,N) if(count[i]!=-INF) ans++;
  
  cout << ans << endl;
}