#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;


int main(void){
  int h,w,i,j;
  bool ipos;
  string a[10];
  
  cin >> h >> w;
  for (i=0;i<h;i++) cin >> a[i];
  
  i=j=0;
  while (1){
    ipos=false;
    ipos|=(i>0 && j>0 && a[i-1][j]==a[i][j-1]);
    ipos|=(i<h-1 && j<w-1 && a[i+1][j]==a[i][j+1]);
    ipos|=(i==h-1 && a[i][j+1]=='.');
    ipos|=(j==w-1 && a[i+1][j]=='.');
    if (ipos){
      cout << "Impossible" << endl;
      return 0;
    }
    if (i==h-1 && j==w-1) break;
    if (i<h-1 && a[i+1][j]=='#') i++;
    else j++;
  }
  
  cout << "Possible" << endl;
  
  return 0;
}