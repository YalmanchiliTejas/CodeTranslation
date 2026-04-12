#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std;

const int INF = 1 << 30;
typedef long long ll;

int main(void){
  int m[5], n[5];
  while(cin >> m[0] >> n[0] && (m[0] || n[0])){
    for(int i = 1; i < 5; i++) cin >> m[i] >> n[i];
    int maxi = 0, sn;
    for(int i = 0; i < 5; i++){
      if(m[i] + n[i] > maxi){
        maxi = m[i] + n[i];
        sn = i;
      }
    }
    cout << (char)('A' + sn) << " " << maxi << endl;
  }
  return 0;
}