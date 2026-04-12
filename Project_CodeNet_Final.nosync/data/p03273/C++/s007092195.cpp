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
  ll h,w;
  cin >> h >> w;
  vector<string> a(h);
  vector<bool> hb(h);
  vector<bool> wb(w);
  for(int i = 0;i < h;i++)hb[i] = true;
  for(int i = 0;i < w;i++)wb[i] = true;
  for(int i = 0;i < h;i++){
    cin >> a[i];
    for(int j = 0;j < w;j++){
      if(a[i][j] == '#')hb[i] = false,wb[j] = false;
    }
  }
  for(int i = 0;i < h;i++){
    for(int j = 0;j < w;j++){
      if(!hb[i] && !wb[j])cout << a[i][j];
    }
    if(!hb[i])cout << endl;
  }
}