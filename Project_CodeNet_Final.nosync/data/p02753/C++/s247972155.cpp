#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll, ll> Pll;
typedef pair<int, Pii > P1;

#define rep(i,n) for(int i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define mp1(a,b,c) P1(a,P(b,c))
#define get_arsize(a) (sizeof(a)/sizeof(a[0]))

const ll MOD = 1000000007;
const double EPS = 1e-10;
const int MAX = 200000;

int main() {
  std::string s;
	cin >> s;
	if (s.find("A") != std::string::npos && s.find("B") != std::string::npos) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}