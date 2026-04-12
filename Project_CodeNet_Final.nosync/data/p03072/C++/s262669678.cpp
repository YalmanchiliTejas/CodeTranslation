#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >>n;
  
  vector<int>h(n);
  for(int i=0; i<n; i++){
    cin >>h[i];
  }
  
  int high = h[0];
  int sum = 1;
  
  for(int i=0; i<n; i++){
    if(h[i+1]>=high&& h[i+1] >= h[i]){
      high = h[i+1];
      sum++;
    }  
  }
  
  printf("%d\n",sum);
  
}