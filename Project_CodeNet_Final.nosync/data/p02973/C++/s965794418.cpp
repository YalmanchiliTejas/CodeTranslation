#include <bits/stdc++.h>
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define ALL(v) v.begin(), v.end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INTXT std::ifstream in ("input.txt"); std::cin.rdbuf(in.rdbuf());
#define INF 1e9

using namespace std;
typedef long long ll;
static const int MOD = 1000000007LL;

signed main() {
  IOS
  int n;
  cin >> n;

  vector<int> nums;
  int max_val = -1 * INF;

  REP(i, n){
    int a;
    cin >> a;
    a = -a;
    if (a >= max_val){
      nums.push_back(a);
      max_val = a;
    }
    else{
      int idx = distance(nums.begin(), upper_bound(nums.begin(), nums.end(), a));
      nums.at(idx) = a;
      max_val = min(nums.at(nums.size() - 1), max_val);
    }
    
    // cout << i << " ";
    // REP(j, nums.size()){
    //   cout << " " << nums.at(j);
    // }
    // cout << endl;
  }
  cout << nums.size() << endl;
}
