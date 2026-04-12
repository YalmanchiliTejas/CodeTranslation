#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	long long N;
    long long MOD = 1000000007;
    cin >> N;
    vector<long long> A(N);
    for (long long i=0; i<N; i++){
      cin >> A.at(i);
    }
    long long result = 0;
    long long sum = 0;
  	for(long long i=1; i<N; i++){
      sum += A.at(i-1);
      sum %= MOD;
      result += sum * A.at(i);
      result %= MOD;
    }
  cout << result << endl;
}