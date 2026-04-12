#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<string> S(n);
  for(int i=0;i<n;++i){
    cin>>S.at(i);
  }

  //26
  string alpha="abcdefghijklmnopqrstuvwxyz";
  string ans;
  for(int i=0;i<26;++i){
    int count=50;
    for(int j=0;j<n;++j){
      int subcount=0;
      for(int k=0;k<S.at(j).size();++k){
        if(S.at(j).at(k)==alpha.at(i)){
          ++subcount;
        }
      }
      count=min(count,subcount);
    }

    for(int l=0;l<count;++l){
      ans += alpha.at(i);
    }
  }

  cout<<ans<<endl;
}