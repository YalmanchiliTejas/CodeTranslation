#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<utility>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<climits>
#include<bitset>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
const int mod=1e9+7;

int main(){
  int x, y, z;
  cin >> x >> y >> z;
  int res = (x-z)/(y+z);
  cout << res << endl;
  return 0;
}