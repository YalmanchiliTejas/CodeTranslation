#include <iostream>
#include<string>
#include <algorithm>
#include <math.h>
using namespace std;
 
int main() {
  long int N, X, M, a[100002]={}, ans = 0, ak, anss[100002]={}, ansnum[100002]={};
  cin >> N >> X >> M;
  for(long int i = 0; i<M; i++){
    a[i] = i*i%M;
  }
  ak = X;
  for(long int j = 0; j<N; j++){
    ans += ak;
    if(anss[ak]==0){
      anss[ak]= ans;
      ansnum[ak] = j;
    }
    else{
      long int num = (N-j-1)/(j-ansnum[ak]);
      ans += num*(ans-anss[ak]);
      j+=num*(j-ansnum[ak]);
    }
    ak = a[ak];
    if(ak == 0)break;
  }
  cout << ans << endl;
  return 0;
}