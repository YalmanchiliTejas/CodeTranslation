#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#include <climits>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int H,W;
char A[10][10];


int main (int argc, char const *argv[])
{
  cin >> H >> W;
  for (size_t j = 1; j <= H; j++)
    for (size_t i = 1; i <= W; i++)
      cin >> A[i][j];

  for (size_t j = 1; j <= H; j++)
    for (size_t i = 1; i <= W; i++)
      if(A[i][j]=='#') {
        if(A[i+1][j]=='#'&&A[i][j+1]=='#') {
          cout << "Impossible" << endl;
          return 0;
        } else if (i==W&&j==H) {
          continue;
        } else if(A[i+1][j]!='#'&&A[i][j+1]!='#') {
          cout << "Impossible" << endl;
          return 0;
        } else if(A[i-1][j]!='#'&&A[i][j-1]!='#'&&(i!=1&&j!=1)) {
          cout << "Impossible" << endl;
          return 0;
        }
      }

  cout << "Possible" << endl;
  return 0;
}
