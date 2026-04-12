#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>

using namespace std;
typedef pair<long long int, long long int> P;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

long long int memo[210000], A[210000];

int main(){
  int N;
  cin >> N;
  for(int i = 0; i <= N; i++){
    memo[i] = INF;
  }
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }
  reverse(A, A + N);
  for(int i = 0; i < N; i++){
    int pos = distance(memo, upper_bound(memo, memo + N, A[i]));
    memo[pos] = A[i];
  }
  cout << distance(memo, lower_bound(memo, memo + N, INF)) << endl;
  return 0;
}
