#include<bits/stdc++.h>
using namespace std;



int main(){
  const long long C = 1000000007;
  int N;
  cin >> N;
  vector<int> V(N);
  long long sum = 0;
  for(int i= 0; i<N; i++){
    int A;
    cin >> A;
    V[i] = A;
    sum += A;
  }
  
  sum -= V[0];
  
  long long sum_mod;
  for(int i= 0; i<N; i++){
    long long X;
    X = V[i]*(sum%C);
    X %= C;
    sum_mod += X;
    //sum_mod %= C;
    sum -= V[i+1];
  }
  
  cout << sum_mod%C << endl;
    
}


