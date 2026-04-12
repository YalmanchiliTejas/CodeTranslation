#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  int N;
  cin >> N;

  vector<int> A(N);
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }
  sort(A.begin(), A.end());

  if(N % 2){
    long long ans1 = - A[N / 2] - A[N / 2 + 1];
    for(int i = 0; i < N / 2; i++){
      ans1 -= 2 * A[i];
    }
    for(int i = N / 2; i < N; i++){
      ans1 += 2 * A[i];
    }

    long long ans2 = A[N / 2 - 1] + A[N / 2];
    for(int i = 0; i < N / 2 + 1; i++){
      ans2 -= 2 * A[i];
    }
    for(int i = N / 2 + 1; i < N; i++){
      ans2 += 2 * A[i];
    }
    cout << max(ans1, ans2) << endl;
  }else{
    long long ans = A[N / 2 - 1] - A[N / 2];
    for(int i = 0; i < N / 2; i++){
      ans -= 2 * A[i];
    }
    for(int i = N / 2; i < N; i++){
      ans += 2 * A[i];
    }
    cout << ans << endl;
  }
}
