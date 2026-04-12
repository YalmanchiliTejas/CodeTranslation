#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int max1 = 0;
  int count = 0;
  for(int i=0;i<n;i++){
      int h;
      cin >> h;
      if(h>=max1){
          max1 = h;
          count++;
      }
  }
  cout << count << endl;
  return 0;
}