#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int ans = 1;
  int n, h[25];
  int judge;
  
  cin >> n;

  for(int i = 0;i < n;i++){
    cin >> h[i];
  }

  for(int i = 1;i < n;i++){
    for(judge = i - 1;judge >= 0 && h[i] >= h[judge];judge--);
    if(judge < 0){
      ans ++;
    }
  }

  cout << ans << endl;
  return 0;
}

