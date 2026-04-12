#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<string.h>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
  int N;
  int ans = 0;
  int maxh = 0;

  cin >> N;

  vector<int> H(N);
  for(int i = 0; i < N; i++){
    cin >> H[i];
    if(maxh <= H[i]){
      ans++;
    }
    maxh = max(maxh, H[i]);
  }

  cout << ans << endl;

}
