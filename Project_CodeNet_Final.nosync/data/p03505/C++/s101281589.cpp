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
  ll k,a,b;
  cin >> k >> a >> b;
  ll res = 0;
  if(a <= b && k > a)res = -1;
  else{
    res++;
    if(k > a){
    ll add = 0;
    if((k - a) % (a - b) != 0)add = 1;
    res += ((k - a) / (a - b) + add) * 2;
    }
  }
  cout << res << endl;
  return 0;
}