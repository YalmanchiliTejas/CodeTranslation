#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

using ll = long long;
#define INF 1e9
#define mod 1e9+7 
vector<int> A, color(1, 0);
int binary(int key){
  int left = -1;
  int right = (int)color.size();

  while(right - left > 1){
    int mid = left + (right - left) /2;
    if(A[mid] < key){
      right = mid;
    }
    else{
      left = mid;
    }
  }
  return right;
}

int main(){
  int N;
  cin >> N;
  A.resize(N);

  REP(i, N){
    cin >> A[i];
  }
  color[0] = A[0];
  FOR(i, 1, N){
    auto it = lower_bound(color.begin(), color.end(), A[i]);
    if(it == color.end()){
      color.back() = A[i];
    }
    else if(it == color.begin()){
      color.insert(color.begin(), (A[i]));
    }
    else{
      it--;
      *it = A[i];
    }
  }

  cout << color.size() << endl;



  return 0;
}
