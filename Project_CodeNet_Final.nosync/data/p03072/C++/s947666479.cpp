#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  
  int i,j;
  int h[n];

  for(i=0; i<n; i++){
    cin >> h[i];
  }

  int res=1;
  
  for(i=1; i<n; i++){
    bool flag = true;
    for(j=0; j<i; j++){
      if(h[i] < h[j]) flag = false;
    }
    if(flag) ++res;
  }
  cout << res << "\n";
  return 0;
}
