#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,n) for(int i = 1; i < n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl "\n"
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;
using vs = vector<string>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll a, const ll b){return ((a)+(b)-1)/b;}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int f;
  cin >> f;
  deque<int> last;
  last.push_back(f);
  last.push_back(inf);
  REP(i,n) {
    int a;
    cin >> a;
    auto it = lower_bound(all(last), a);
    if(it == last.begin()) {
      last.push_front(a);
    }
    else {
      it--;
      *it = a;
    }
  }
  int ans = sz(last);
  cout << ans-1 << endl;
}