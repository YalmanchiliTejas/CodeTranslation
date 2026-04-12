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
  int h,w;
  cin >> h >> w;
  vector<string> a(h);
  int count = 0;
  for(int i = 0;i < h;i++){
    cin >> a[i];
    for(int j = 0;j < w;j++){
      if(a[i][j] == '#')count++;
    }
  }
  bool res = false;
  if(count == h + w - 1)res = true;
  if(res)cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
}