#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int ans = 100*a + 10*b + c;
  if(ans%4==0) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}
