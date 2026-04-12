#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1e18;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; ++i){
    cin >> A[i];
  }
  vector< vector<long long> > DP(N+1,vector<long long>(N+1,-INF));
  for(int i = 0; i <= N; ++i) DP[i][i] = 0;
  for(int i = 1; i <= N; ++i){
    for(int j = 0; j <= N-i; ++j){
      DP[j][i+j] = -max(A[j+i-1]+DP[j][i+j-1],A[j]+DP[j+1][i+j]);
      //cerr << j << " " << j+i << " " << DP[j][i+j] << endl;
    }
  }
  cout << -DP[0][N] << endl;
}
