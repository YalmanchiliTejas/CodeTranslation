#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;
using llong = long long;

using P = pair<int,int>;
P X[200000];
int B[200000];
int main(){
  int N;
  cin >> N;
  for(int i=0;i<N;++i){
    cin >> X[i].first;
    X[i].second = i;
  }
  sort(X,X+N);
  for(int i=0;i<N;++i){
    if(i>(N-1)/2){
      B[X[i].second] = X[(N-1)/2].first;
    }else{
      B[X[i].second] = X[(N-1)/2+1].first;
    }
  }

  for(int i=0;i<N;++i){
    cout << B[i] << endl;
  }
  return 0;
}