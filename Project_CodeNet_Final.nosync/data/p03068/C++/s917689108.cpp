#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
  int N, K;
  string S, ans;
  cin >> N >> S >> K;
  ans = S;
  for(int i=0; i<N; i++){
    if(S[K-1]!=ans[i])ans[i]='*';
  }

  cout << ans << endl;
}