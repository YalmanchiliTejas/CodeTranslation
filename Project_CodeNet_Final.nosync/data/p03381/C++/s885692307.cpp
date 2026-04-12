#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector< pair<int,int> > A(N);
  int a;
  for(int i = 0; i < N; ++i){
    cin >> a;
    A[i] = make_pair(a, i);
  }
  sort(A.begin(), A.end());
  vector<int> ans(N);
  for(int i = 0; i < N; ++i){
    if(i < N/2) ans[A[i].second] = A[N/2].first;
    else ans[A[i].second] = A[N/2-1].first;
  }
  for(int i = 0; i < N; ++i){
    cout << ans[i] << endl;
  }
  return 0;
}
