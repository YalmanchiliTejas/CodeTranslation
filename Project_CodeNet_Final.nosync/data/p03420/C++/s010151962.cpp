#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  ll n,k;
  cin >> n >> k;
  ll res = 0;
  for(int i = 1;i <= n;i++){
    if(k >= i)continue;
    res += n;
    if(k > 0){
      ll base = n / i;
      res -= base * k;
      ll add = n % i;
      res -= min(add,k - 1);
    }
  }
  cout << res << endl;
  return 0;
}