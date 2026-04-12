#include<iostream>
using namespace std;
int main()
{
  int N;
  cin >> N;
  int H[N];
  for(int i=0; i<N; i++){
    cin >> H[i];
  }
  int dp[N], count=1;
  dp[0] = H[0];
  for(int i=1; i<N; i++){
    dp[i] = max(dp[i-1], H[i]);
    if(dp[i-1] <= H[i])
      count++;
  }
  cout << count;
  return 0;
}
    