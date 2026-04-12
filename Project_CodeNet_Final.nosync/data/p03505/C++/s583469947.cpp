#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
typedef long long ll;

int main(){
  ll K, A, B; cin >> K >> A >> B;
  if (A <= B){
    if (A >= K){
      cout << 1 << endl;
    }else{
      cout << -1 << endl;
    }
  }else{
    ll N1 = (K - B) / (A - B) + 1;
    if((K - B) % (A - B) == 0) N1--;
    cout << 2 * (N1 - 1) + 1 << endl;
  }
  
  

  return 0;
}
