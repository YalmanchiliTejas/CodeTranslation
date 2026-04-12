#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <cstring>
#include <iomanip>
#include <utility>
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n) for(int i=1;i<=(n);i++)
#define lol long long
#define mp make_pair
#define fi first
#define se second
#define pu push_back
#define SYOU(x) setprecision(x+1)
#define abs(x,y) (max(x,y)-min(x,y))
#define SUM(n) ((n)+1)*(n)/2
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = (1e9)+7;
#define all(v) v.begin(),v.end()
using namespace std;
using pii = pair<int,int>;
typedef vector<int> vit;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  string s;
  int n, count[55][50] = {};
  cin >> n;
  rep(i,n){
    cin >> s;
    rep(j,s.size()){
      count[i][s[j] - 'a'] ++;
    }
  }
  rep(i,26){
    int minv = count[0][i];
    reps(j,n - 1){
      minv = min(count[j][i], minv);
    }
    rep(j,minv){
      cout << (char)('a' + i);
    }
    //   cout << '\n';
  }
  cout << '\n';
  return 0;
}
