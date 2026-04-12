#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

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

//const value
//const ll MOD = 1e9 + 7;
//const int dx[] = {0,1,0,-1};//{0,0,1,1,1,-1,-1,-1};
//const int dy[] = {1,0,-1,0};//{1,-1,0,1,-1,0,1,-1};

//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

const ll INF = 1e15;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  VLL a(n);
  rep(i,n) cin >> a[i];
  deque<ll> maxArray;
  maxArray.push_back(a[0]);

  FOR(i, 1,n){
    if( lower_bound(all(maxArray),a[i]) == maxArray.begin()){
      maxArray.push_front(a[i]);
      //cout << "hi"<< a[i] << endl;
    }else{
      *(lower_bound(all(maxArray),a[i]) - 1) = a[i];
      //cout << a[i] << endl;
    }

  }
  cout << maxArray.size()<< endl;
  return 0;
}
