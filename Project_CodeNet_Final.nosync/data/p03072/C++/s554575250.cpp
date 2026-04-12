#include <bits/stdc++.h>
using namespace std;

int main(){
  int n , h ;
  int ans = 0;
  int saidai = 0 ;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> h ;
    if(saidai<=h) {
      ans++;
      saidai = h;
    }
  }
    
  cout << ans << endl;
}

