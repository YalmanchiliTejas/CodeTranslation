#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define ALL(a)  (a).begin(),(a).end()

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//sort(v.rbegin(), v.rend(), [](auto& x, auto& y){return x[1] < y[1];});
//cout << fixed << setprecision(10) << ans << defaultfloat << endl;
typedef long long ll;
typedef vector<int> Vi;
typedef vector<ll> Vl;
typedef vector<double> Vd;
typedef vector<string> Vs;

vector< int64_t > divisor(int64_t n) {
  vector< int64_t > ret;
  for(int64_t i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

int main() {
    int N;
    ll t;
    cin >> N;
    Vl ans(1);
    cin >> ans[0];
    FOR(i,1,N) {
        cin >> t;
        if (t <= ans[0]) ans.insert(ans.begin(),t);
        else {
            auto it = lower_bound(ALL(ans), t);
            --it;
            *it = t;
            }
        }
    cout << ans.size() << endl;
    }