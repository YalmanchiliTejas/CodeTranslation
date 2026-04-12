#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <limits>
#include <iomanip>

using namespace std;
long long point[3000][3000];
int N;
int a[3000];

long long rec(int left, int right){
   int turn = (N-(right-left+1))%2;
   if(left > right) return 0;
   if(point[left][right]!=LLONG_MAX) return point[left][right];
   if(turn == 0 ){
      point[left][right] = max(a[left] + rec(left+1, right), a[right]+rec(left,right-1));
   }
   else{
      point[left][right] = min(-a[left] + rec(left+1, right), -a[right]+rec(left,right-1));
   }
   return point[left][right];
}

int main(){
  cin >> N;
  for(int i = 0 ; i <N; i++) cin >> a[i];
  for(int i = 0 ; i < 3000; i++){
     for(int j = 0 ; j < 3000; j++){
        point[i][j] = LLONG_MAX;
     }
  }
  cout << rec(0, N-1) << endl;
  return 0;
}
