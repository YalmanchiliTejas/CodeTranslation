#include <bits/stdc++.h>
using namespace std;
 
#define INF 1e9+7
 
int main(){
  int N,a;
  cin >> N;
  int A[N];
  multiset<int> LIS;
  for(int i=0; i<N; i++){
    cin >> a;
    A[i] = a;
  }
  LIS.emplace(A[0]);
  for(int i=1; i<N; i++){
    if(A[i]<=*LIS.begin()){
      LIS.emplace(A[i]);
    }else{
      auto it = LIS.lower_bound(A[i]);
      if(it!=LIS.begin()) it--;
      LIS.erase(it);
      LIS.emplace(A[i]);
    }
  }
  cout << LIS.size() << endl;
  return 0;
}