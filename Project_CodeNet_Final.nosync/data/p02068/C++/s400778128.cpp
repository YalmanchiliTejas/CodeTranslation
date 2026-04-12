#include <bits/stdc++.h>

using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }

  vector<int> primeList;
  primeList.push_back(2);
  
  vector<bool> check(100001, false);

  for(int i = 3; i <= 100000; i += 2){
    if(!check[i]){
      primeList.push_back(i);
      check[i] = true;
      for(int j = i * i; j <= 100000; j += 2){
	check[j] = true;
      }
    }
  }

  for(int i = 0; i < N; i++){
    int temp = A[i];

    for(int prime: primeList){
      if(temp % prime == 0){
	temp /= prime;
      }
    }

    if(temp > 1){
      primeList.push_back(temp);
    }
  }

  long long ans = 0;
  for(int prime: primeList){
    long long tempSum = 0;
    for(int i = 0; i < N; i++){
      if(A[i] % prime == 0){
        tempSum += A[i];
      }
    }

    ans = max(ans, tempSum);
  }

  cout << ans << endl;
}

