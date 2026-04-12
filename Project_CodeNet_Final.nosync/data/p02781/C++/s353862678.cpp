#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
 
int main(){
  string N;
  cin>>N;
  int K;
  cin>>K;
  ll B[N.size()][8]={};
  if(N.size()<K) cout<<0<<endl;
  else{
    B[0][1]=1;
    B[0][2]=1;
    B[0][3]=N[0]-'1';
    rep(i,N.size()-1){
      rep(j,8){
        if(j%2){
          B[i+1][j]+=B[i][j];
          if(j!=1) B[i+1][j]+=B[i][j-2]*9;
        }
      }
      if(N[i+1]=='0'){
        rep(j,8) if(j%2==0) B[i+1][j]+=B[i][j];
      }else{
        rep(j,8){
          if(j%2==0){
            B[i+1][j+1]+=B[i][j];
            if(j!=6){
              B[i+1][j+2]+=B[i][j];
              B[i+1][j+3]+=B[i][j]*(N[i+1]-'1');
            }
          }
        }
      }
    }
    cout<<B[N.size()-1][K*2]+B[N.size()-1][K*2+1]<<endl;
  }
  return 0; 
}