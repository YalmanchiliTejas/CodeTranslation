#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  int n,tot=0,maxh=1;
  int h[110];
  cin >> n;
  for (int i=0; i< n;i++) cin >> h[i];

  
  for (int i=0; i< n;i++){
    if (i == 0){
      maxh = h[i];
      tot++;
    }else{
      if (h[i] >= maxh){
	tot++;
      }
      maxh = max(h[i],maxh);
    }
  }

  cout << tot;
  
}

