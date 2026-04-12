#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  int h[n];
  
  for(int i=0;i<n;i++){
    cin >> h[i];
  }
  
  int c=0;
  int m=h[0];
  
  for(int i=0;i<n;i++){
    if(m<=h[i]){
      c++;
      m=h[i];
    }
  }
  cout << c <<endl;
}
    