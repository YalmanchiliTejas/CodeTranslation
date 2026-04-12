#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  int count=1;
  cin >> n;
  vector<int> height(n);
  
  for(int i=0; i<n; i++){
    cin >> height.at(i);
  }
  int max = height.at(0);
  
  for(int i=1; i<n; i++){
    if(max <= height.at(i)){
      count++;
      max = height.at(i);
    }
  }
  
  cout << count << endl;
  
    
}