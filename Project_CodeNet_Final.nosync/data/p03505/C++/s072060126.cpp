#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <complex>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 100010


int main(){
  ll k,a,b;

  cin >> k >> a >> b;

  if(k <= a){
    cout << 1 << endl;
    return 0;
  }

  if(a-b <= 0){
    cout << -1 << endl;
    return 0;
  }

  cout << (k - a + (a-b-1)) / (a - b) * 2 + 1 << endl;
  
  return 0;
}
