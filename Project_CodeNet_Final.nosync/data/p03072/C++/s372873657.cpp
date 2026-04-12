#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int h[n];
  int max = 0;
  int cnt = 0;
  for(int i = 0;i < n;i++){
    cin >> h[i];
    if(max <= h[i]){
      max = h[i];
      cnt++;
    }    
  }
  cout << cnt << endl;
}