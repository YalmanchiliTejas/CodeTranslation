#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<string> S(N);
  for (int i=0; i<N; i++) cin>>S[i];
  int num[50][27] = {};
  for (int i=0; i<N; i++){
    for (int j=0; j<S[i].size(); j++){
      int id = S[i][j]-'a';
      num[i][id]++;
    }
  }
  string ans="";
  for (int j=0; j<27; j++){
    int mn = num[0][j];
    for (int i=0; i<N; i++)
      mn = min(mn,num[i][j]);
    for (int i=0; i<mn; i++)
      ans += 'a' + j;
  }
  cout<<ans<<endl;
  return 0;
}
