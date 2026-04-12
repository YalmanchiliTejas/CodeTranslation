#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  string S;
  int N,K;
  cin>>N>>S>>K;
  for(char c:S){
    if(c==S[K-1])
      cout<<c;
    else
      cout<<'*';
  }
  cout<<endl;
}