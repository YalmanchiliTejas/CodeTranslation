#include <bits/stdc++.h>
using namespace std;
  
int main() {
  int n;
  
  cin >> n;
  
  int total=0,count=1;
  
  for(int i=0;i<n;i++){
    total+=800;
    if(count%15==0){
      total-=200;
    }
    count++;
  }
  
  cout << total;
  
}
