#include<iostream>
using namespace std;
int main(){
  int n, h, dp[20], cnt=1;
  cin >> n;
  cin >> dp[0];
  for(int i=1; i<n; i++){
    cin >> h;
    if(h >= dp[i-1]){
      cnt ++;
      dp[i] = h;
    }else{
      dp[i] = dp[i-1];
    }
  }
  cout << cnt << endl;
  return 0;
}