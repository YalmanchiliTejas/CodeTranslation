#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const double EPS = 1e-9;


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int r,g,b;
  cin>>r>>g>>b;
  if((10 * g + b) % 4 == 0) {
    cout << "YES" << endl;
  } else {
    cout <<"NO"<<endl;
  }

  return 0;
}
