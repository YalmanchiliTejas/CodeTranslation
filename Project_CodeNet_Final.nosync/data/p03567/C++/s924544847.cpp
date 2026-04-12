#include <bits/stdc++.h>
#define rep0(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i < (n); ++i)
#define REP(i,a,b) for (int i = a; i < (b); ++i)
#define mREP(i,a,b) for (int i = a; i > (b); --i)
#define all(x) (x).begin(),(x).end()
const int INF = 1000000007;
typedef long long ll;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int main(){
  string s;
  cin >> s;
  bool ans = false;
  rep0(i,s.size()-1){
    if(s[i] == 'A' && s[i+1] == 'C')ans = true;
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
