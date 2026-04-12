#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

int main()
{
  int H,W,cnt=0;
  cin>>H>>W;
  string ans="Impossible";
  string A;
  for(int i=0;i<H;i++){
    cin>>A;
    for(int j=0;j<W;j++){
      if(A[j]=='#') cnt++;
    }
  }
  if(cnt==H+W-1) ans="Possible";
  cout<< ans <<endl;
}
