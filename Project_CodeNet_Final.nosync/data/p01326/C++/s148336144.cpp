#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
  for(int N;cin>>N,N;){
    string b[1000];
    for(int i=0;i<N;i++){
      cin>>b[i];
    }
    int dp[1001]={1};
    for(int i=0;i<N;i++){
      vector<string> bp[4]={
	{"0xxxxxxx"},
	{"110yyyyx","10xxxxxx"},
	{"1110yyyy","10yxxxxx","10xxxxxx"},
	{"11110yyy","10yyxxxx","10xxxxxx","10xxxxxx"}
      };
      for(int j=0;j<4;j++){
	if(N-i<bp[j].size())continue;
	bool f=false;
	int x=0,y=0;
	bool yz=false;
	for(int k=0;k<bp[j].size();k++){
	  for(int l=0;l<8;l++){
	    if(bp[j][k][l]=='0'||bp[j][k][l]=='1'){
	      f|=b[i+k][l]==(bp[j][k][l]^'0'^'1');
	    }else if(bp[j][k][l]=='y'){
	      y+=b[i+k][l]=='x';
	      yz|=b[i+k][l]=='1';
	    }else{
	      x+=b[i+k][l]=='x';
	    }
	  }
	}
	if(!f){
	  long long yf=(j==0)?1:(1LL<<y)-!yz;
	  const int M=1000000;
	  dp[i+bp[j].size()]=(dp[i+bp[j].size()]+(yf<<x)%M*dp[i])%M;
	}
      }
    }
    cout<<dp[N]<<endl;
  }
}