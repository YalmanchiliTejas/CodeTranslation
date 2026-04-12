#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
#include<list>
using namespace std;
int inf = 1000000000;

int main(void) {
  int n;
  while(cin >> n){
    if( n == 0 ) break;
    vector< vector<int> > a(n, vector<int>(n, -1));
    int cnt = 0;
    int x = n/2;
    int y = x + 1;
    while( cnt < n*n ){
      if( a[y][x] == -1 ){
        a[y][x] = cnt + 1;
        x += 1; y += 1;
        cnt++;
      }else{
        x -= 1; y += 1;
      }
      if( x >= n ) x = 0;
      else if( x < 0 ) x = n-1;
      if( y >= n ) y = 0;
      else if( y < 0 ) y = n-1;

    }
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        printf("%4d", a[i][j]);
      }
      cout << endl;
    }

  }

  return 0;
}

// EOF