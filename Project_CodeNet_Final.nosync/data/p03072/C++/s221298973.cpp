#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  int count=0;
  cin >> n;
  vector<int> h(n);
  for(int i=0;i<n;i++){
    cin >> h[i];
  }
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      if(h[i]<h[j]){
       break;
      }else{
        if(i-1==j){
          count++;
        }
      }
    }
  }
  cout << count+1 << endl;
}