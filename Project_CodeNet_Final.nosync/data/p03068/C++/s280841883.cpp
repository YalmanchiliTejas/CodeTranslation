#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define int long long
#define str string
#define rep(x,y) for(int i=x;i<y;i++)
#define REP(x,y) for(int j=x;j<y;j++)
#define all(x) x.begin(),x.end()
signed main(){
  int A,B,C,N,K;
  str S,W,T;
  cin>>N>>S;
  cin>>K;
  rep(0,N){
    if(S.at(K-1)!=S.at(i)){
      S.at(i)='*';
    }

  }
      cout<<S<<endl;
}
