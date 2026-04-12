#include<iostream>
using namespace std;

int main(){
  int N,K;
  cin >> N;
  cin >> K;
  long long int cnt = 0;
  int s;
    for(int b = K + 1;b <= N;b++){
      int l = N / b;
      cnt += l * (b - K);
      if(N - l * b > K - 1){
	cnt += N -l * b - (K - 1);
      }
    }
      if(K == 0)cnt -= N;
  cout << cnt << endl;
}
