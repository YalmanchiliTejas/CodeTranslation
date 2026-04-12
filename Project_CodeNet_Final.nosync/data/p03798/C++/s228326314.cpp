#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,l,r) for(int i=(int)(l);i<(int)(r);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
template<class T>bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,T b){if(a>b){a=b;return 1;}return 0;}

/*{
}*/

using vi = vector<int>;
using vvi = vector<vi>;
using P = pair<int,int>;

//constexpr int mod = 1e9+7;
//constexpr int inf = 1LL<<60;

signed main() {
  int n;
  string S;
  cin >> n >> S;

  vi s;
  for(char c : S){
    s.emplace_back(c == 'x');
  }

  rep(i, 0, 2) rep(j, 0, 2){
    // 1 = W, 0 = S
    /*
    o S same 0 0
    x S diff 1 0
    o W diff 0 1
    x W same 1 1
    */
    vi t;
    t.emplace_back(i);
    t.emplace_back(j);

    rep(k, 1, n-1){
      t.emplace_back((t[k-1]+s[k]+t[k])%2);
    }

    if((t[n-2]+s[n-1]+t[n-1])%2 != t[0]) continue;
    if((t[n-1]+s[0]+t[0])%2 != t[1]) continue;

    for(int k : t){
      cout << (k ? 'W' : 'S');
    }
    cout << endl;
    return 0;
  }

  cout << -1 << endl;

  return 0;
}

