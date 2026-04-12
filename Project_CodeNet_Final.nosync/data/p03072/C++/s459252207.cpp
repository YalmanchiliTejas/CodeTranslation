#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  int ans =0;
  for(int i= 0;i<n;i++){
    int maxhi ;
    int h;
    cin >> h;
    if( maxhi<= h){
      maxhi = h;
      ans +=1;
    }
  }
  cout << ans;
}