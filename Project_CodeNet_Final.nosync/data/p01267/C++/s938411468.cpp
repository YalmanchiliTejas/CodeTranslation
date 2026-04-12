#include<bits/stdc++.h>
#define REP(i,s,n) for(int i=s ; i < n ; i++)
#define rep(i,n) REP(i,0,n)
using namespace std;
int main(){
  
  int N,A,B,C,X;
  int Y[10000];
  
  while(1){
    
    cin >>N>>A>>B>>C>>X;
    
    if(N==0 && A==0 && B==0 && C==0 && X==0)break;
    
    rep(i,N){
      cin >>Y[i];
    }
    
    int cnt=0;
    bool check=true;
    
    rep(i,10001){
      
      if(Y[cnt]==X){
	cnt++;
      }
      
      if(cnt == N){
	cout <<i<<endl;
	check=false;
	break;
      }
      
      X=(A*X+B)%C;
    }
    
    if(check)cout <<"-1"<<endl;
    
  }
  
  return 0;
}
  