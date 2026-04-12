#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;


int main(){
  int r, g, b;
  cin >> r >> g >> b;
  int ans = r;
  ans *= 10;
  ans += g;
  ans *= 10;
  ans += b;
  if(ans % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}
