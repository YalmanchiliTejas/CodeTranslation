#include <bits/stdc++.h>
using namespace std;
int main(){
  int K,N;
  string S;
  cin >>N>>S>>K;
  char t=S.at(K-1);
  string ans;
  for(int i=0;i<S.size();i++){
    if(S.at(i)!=t){ans.push_back('*');}
    else{ans.push_back(S.at(i));}
  }
   cout <<ans<<endl;
}