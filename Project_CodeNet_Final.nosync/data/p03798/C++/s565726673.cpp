#include <cstdio>
#include <cstring>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;
  char ans[n];
  for(int i=0;i<n;i++)
    cin >> ans[i];

  int c[4][100001]={};
  c[0][0] = 0;   //0=s  1=w
  c[0][1] = 0;
  c[1][0] = 0;
  c[1][1] = 1;
  c[2][0] = 1;
  c[2][1] = 0;
  c[3][0] = 1;
  c[3][1] = 1;

  for(int i=1;i<n-1;i++){
    if(ans[i]=='o'){
      for(int j=0;j<4;j++){
        if(c[j][i]==1){
          c[j][i+1] = 1 - c[j][i-1];
        }else{
          c[j][i+1] = c[j][i-1];
        }
      }
    }else{
      for(int j=0;j<4;j++){
        if(c[j][i]==1){
          c[j][i+1] = c[j][i-1];
        }else{
          c[j][i+1] = 1 - c[j][i-1];
        }
      }
    }
  }

  for(int i=0;i<4;i++){
    if(

      (
      ((c[i][n-1] == c[i][1]) && (c[i][0] == 0) && (ans[0] == 'o') )
      ||
      ( (c[i][n-1] == c[i][1]) && (c[i][0] == 1) && (ans[0] == 'x') )
      ||
      ( (c[i][n-1] != c[i][1]) && (c[i][0] == 0) && (ans[0] == 'x') )
      ||
      ( (c[i][n-1] != c[i][1]) && (c[i][0] == 1) && (ans[0] == 'o') )
      )

      &&

      (
      ((c[i][n-2] == c[i][0]) && (c[i][n-1] == 0) && (ans[n-1] == 'o') )
      ||
      ( (c[i][n-2] == c[i][0]) && (c[i][n-1] == 1) && (ans[n-1] == 'x') )
      ||
      ( (c[i][n-2] != c[i][0]) && (c[i][n-1] == 0) && (ans[n-1] == 'x') )
      ||
      ( (c[i][n-2] != c[i][0]) && (c[i][n-1] == 1) && (ans[n-1] == 'o') )
      )



      )

    {
      for(int j=0;j<n;j++){
        if(c[i][j]==1)
          cout << 'W';
        else
          cout << 'S';
      }
      cout << endl;
      return 0;
    }
  }

  cout << -1 <<endl;

  return 0;
}
