#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define int long long

using namespace std;


signed main(){
  int N;
  string S;
  int K;
  char okikae;


  cin>>N;
  cin>>S;
  cin>>K;
  okikae = S[K-1];
  rep(i, N){
    if(S[i]==okikae){
      cout << okikae;
    }else{
      cout << '*';
    }
  }
  cout << endl;
  
  return 0;
}
