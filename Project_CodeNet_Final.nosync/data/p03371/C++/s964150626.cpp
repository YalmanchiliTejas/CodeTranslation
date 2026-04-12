#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define Sort(a) sort(a.begin(), a.end())
#define fin(ans) cout << (ans) << endl
const int INF = 1<<30;
const ll MOD = 1000000007;

int main() {
  ll A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  
  ll min = A*X+B*Y, mp = std::max(X,Y);
  for(int i=mp*2; i>=0; i-=2){
      ll sum = C*i;
      if(X-i/2>0) sum+=A*(X-i/2);
      if(Y-i/2>0) sum+=B*(Y-i/2);
      min = std::min(min,sum);
      //cout << i << " " << sum << endl;
  }

  cout << min << endl;
  
}