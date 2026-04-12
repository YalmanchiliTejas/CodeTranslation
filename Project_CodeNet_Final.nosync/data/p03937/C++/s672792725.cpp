#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
#define int long long


signed main(void){
  char a[9][9];
  int h,w;
  cin >> h >> w;

  for(int i = 0; i < h; i++){
    cin >> a[i];
  }

  int i = 0;
  int j = 0;
  while(true){
    a[i][j] = '.';
    if(j<w-1 && a[i][j+1] == '#'){
      j++;
      continue;
    }else if(i < h-1 && a[i+1][j] == '#'){
      i++;
      continue;
    }else{
      break;
    }
  }

  bool ret = true;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(a[i][j]=='#'){
        ret = false;
      }
    }
  }

  if(ret)cout << "Possible\r\n";
  else cout << "Impossible\r\n";
}
