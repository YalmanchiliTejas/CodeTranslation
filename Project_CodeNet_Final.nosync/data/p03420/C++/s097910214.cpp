#include<iostream>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;

  if(K == 0){
    cout << static_cast<long long>(N) * N << endl;
    return 0;
  }

  long long ans = 0;
  for(int b = K + 1; b <= N; b++){
    // a = K, ..., b - 1,
    //     b + K, ..., 2b - 1, ..

    // nb - 1 <= N
    // n <= (N + 1) / b
    long long whole_size = (b - 1) - K + 1, whole_cnt = (N + 1) / b;
    ans += whole_size * whole_cnt;

    // nb + K <= N
    // n <= (N - K) / b
    long long partial_n = (N - K) / b;
    if(partial_n > whole_cnt - 1){
      ans += N - (partial_n * b + K) + 1;
    }
  }
  cout << ans << endl;
}

