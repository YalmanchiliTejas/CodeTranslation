#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

//container util
#define all(x) (x).begin(),(x).end()

//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;


//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}


int main(){
  ll n;
  cin >> n;
  VI H(n);
  rep(i,n){
    cin >> H[i];
  }
  int maxHeight = 0;
  ll ans = 0;
  rep(i,n){
    if(maxHeight <= H[i]){
      ans++;
      maxHeight = max(H[i],maxHeight);
    }
  }
  cout << ans << endl;
  return 0;
}
