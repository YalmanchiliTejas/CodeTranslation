#include<bits/stdc++.h>
using namespace std;
#define min(a, b) (a > b ? b : a)
#define max(a, b) (a > b ? a : b)

int main(){
  int N,K;
  cin >> N >> K;
  long long int res = 0;

  for(int b = K + 1;b <= N;b++){
    int alpha = N / b;
    res += alpha * (b - K) + max(0,N - alpha * b - K + 1);
  }
  if(K == 0){
    res -= N;
  }
  cout << res << endl;
  return 0;
}