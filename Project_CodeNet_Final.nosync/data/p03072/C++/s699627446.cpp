#include <bits/stdc++.h>
using namespace std;


int main() {

  int n;
  cin>>n;

  int wk_max=0, cnt=0;
  for(int i=0;i<n;i++){
    int h;
    cin>>h;
    if(h>=wk_max){
      cnt++;
      wk_max=max(h,wk_max);
    }
  }

  cout<<cnt<<endl;

  return 0;
}

