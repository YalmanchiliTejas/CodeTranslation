#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
const ll MOD=1000000007;



int main() {
  string N,N2;
  int K,S=0;
  vector<int> T(0);
  cin>>N>>K;
  N2=N;
  S=N.size();
  rep(i,S){

      T.push_back(N.at(i)-'0');
  }
  
  if(K==1){cout<<9*(S-1)+T.at(0)<<endl;}
  if(K==2){
      if(S<2){cout<<0<<endl;}
      else{
      ll ans=0;
      bool judge=true;//2桁目以降0が続いているかどうか
      for(int i=2;i<S;i++){ans+=81*(i-1);}
      rep(i,S-1){
          if(judge){ans+=T.at(0)*9-9+T.at(i+1);}
          else{ans+=T.at(0)*9;}
          if(T.at(i+1)!=0){judge=false;}
      }
      cout<<ans<<endl;}
  }
  if(K==3){
      if(S<3){cout<<0<<endl;}
      else{
      ll ans=0;
      for(int i=3;i<S;i++){ans+=729*(i-1)*(i-2)/2;}
      
      ans+=(T.at(0)-1)*9*9*(S-1)*(S-2)/2;
      bool j=false;
      vector<int> T2(0);
      for(int i=1;i<S;i++){
          if(T.at(i)!=0){j=true;}
          if(j){T2.push_back(T.at(i));}
      }
      int S2=T2.size();

      bool judge=true;//2桁目以降0が続いているかどうか
      for(int i=2;i<S2;i++){ans+=81*(i-1);}
      rep(i,S2-1){
          if(judge){ans+=T2.at(0)*9-9+T2.at(i+1);}
          else{ans+=T2.at(0)*9;}
          if(T2.at(i+1)!=0){judge=false;}
      }
      cout<<ans<<endl;}
  }
}