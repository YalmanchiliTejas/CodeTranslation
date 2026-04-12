#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> h(n);
  for(int i=0;i<n;i++)
    cin >> h.at(i);
  
  int a=0;
  int k=0;
  
  for(int i=0;i<n;i++){
    if(a<=h.at(i)){
      a=h.at(i);
      k++;
    }
  }
  
  cout << k << endl;
}