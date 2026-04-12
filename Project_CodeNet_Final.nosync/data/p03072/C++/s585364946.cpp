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
  int N;
  cin >> N;
  int h[N];
  for(int i=0;i<N;i++) cin >> h[i];

  int ans = 0;
  for(int i=0;i<N;i++){
    bool isok = true;
    for(int j=0;j<i;j++){
      if(h[i] < h[j]) isok = false;
    }
    if(isok) ans++;
  }

  cout << ans << endl;
  return 0;
}
