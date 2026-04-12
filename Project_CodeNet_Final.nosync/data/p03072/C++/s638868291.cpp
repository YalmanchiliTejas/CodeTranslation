#include <algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>

#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> h;
  h.resize(n);
  int ii,jj,num =1,height;
  for(ii=0;ii<n;ii++){
    cin  >> h[ii];
  }
  
  for(ii=1;ii<n;ii++){
    height = h[ii];

    for(jj=ii-1;jj>=0;jj--){
      //cout << "height" << height << "h[jj]" << h[jj] << endl;
      if(height < h[jj]){
	break;
      }
      
      if(jj == 0){
	num += 1;
      }
    }
  }
  
  cout << num << endl;
  
  return 0;
}
