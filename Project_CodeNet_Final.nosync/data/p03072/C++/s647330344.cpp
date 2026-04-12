#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> h(n);
  for (int i=0;i<n;i++){
    cin>>h.at(i);
  }
  
  int hotel;
  
  for (int i = 0; i < n; i++) {
    int j=0;
    bool view=1;
    
    while(view==1 and j<i){
      if(h.at(j)>h.at(i)){
        view=0;
      }
      j++;
    }
    
    hotel+=view;
  }
  
  cout<<hotel;

}