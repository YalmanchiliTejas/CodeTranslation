#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; vector<int64_t> X(200010), sortX(200010);

  cin >> N;
  for(int i=0; i<N; i++){
    cin >> X[i]; sortX[i] = X[i];
  }

  sort(sortX.begin(), sortX.begin()+N);

  map<int64_t, int64_t> median;

  for(int i=0; i<N; i++){
    if(i < N/2){
      median[sortX[i]] = sortX[N/2];
    } else {
      median[sortX[i]] = sortX[N/2-1];
    }
  }

  for(int i=0; i<N; i++){
    cout << median[X[i]] << endl;
  }
}
