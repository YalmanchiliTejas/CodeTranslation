#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
int main(){
  int h,w;
  cin >> h >> w;
  vector<string> a(h);
  for(int i = 0;i < h;i++)cin >> a[i];

  int cnt = 0;
  for(int i = 0;i < h;i++){
    for(int j = 0;j < w;j++){
      if(a[i][j] == '#')cnt++;
    }
  }

  if(cnt != h + w - 1)cout << "Impossible" << endl;
  else cout << "Possible" << endl;
}