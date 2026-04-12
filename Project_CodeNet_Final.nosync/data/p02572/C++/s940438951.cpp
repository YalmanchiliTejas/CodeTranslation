#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
  int N;
  int mod = 1000000007;
  cin >> N;
  vector<int> A(N);
  long long sum =0;
  
  for(int i=0; i<N; i++){
    cin >>A[i];
    sum += A[i];
    sum %= mod;
  }
  
  long ans = 0;
  
  for(int i=0; i < N; i++){
    sum -= A[i];
    if(sum < 0){
      sum+=mod;
    }
    ans += A[i] * sum;
    ans %= mod;
  }
  
  cout << ans;
  return 0;
	
}
  