#include <bits/stdc++.h>
using namespace std;
int max_z(int a,vector<int>s){
  if(a==0){
    return s.at(0);
  }
  int t =max_z(a-1,s);
  return max(s.at(a),t);
}
int main() {
  int N;
  cin>>N;
  vector<int> s(N);
    for(int i=0;i<N;i++){
        cin>>s.at(i);
    }
  int ans=0;
  for(int i=0;i<N;i++){
    if (i==0||(i>=1&&s.at(i)>=max_z(i-1,s))){
      ans++;
    }
  }
  cout << ans << endl;
}