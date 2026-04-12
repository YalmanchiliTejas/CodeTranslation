#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  vector<long int> M(N);
  long int s=0;
  long int S;
  long int answer;
  for(int i=0; i<N; i++){
    cin >> A.at(i);
  }
  for(int i=N; i>1; i--){
    s+=A.at(i-1);
    S=s%1000000007;
    M.at(i-2)=(S*A.at(i-2))%1000000007;
  }
  for(int i=0; i<N-1; i++){
    answer+=M.at(i);
  }
  cout << answer%1000000007 <<endl;
}