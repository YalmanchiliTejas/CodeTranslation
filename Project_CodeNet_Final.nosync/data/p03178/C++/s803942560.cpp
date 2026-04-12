#include <iostream>

const int MOD=1e9+7;

void addmod(int& x,int y){
  x=(x+y)%MOD;
}

int dp[100];
int tmp[100];

int main(){
  std::string K;
  int D;
  std::cin>>K>>D;
  int prefix=0;
  for(char c:K){
    for(int rem=0;rem<D;rem++){
      for(int d=0;d<10;d++){
	addmod(tmp[(rem+d)%D],dp[rem]);
      }
    }
    for(int rem=0;rem<D;rem++){
      dp[rem]=tmp[rem];
      tmp[rem]=0;
    }
    for(int d=0;d<c-'0';d++){
      addmod(dp[(prefix+d)%D],1);
    }
    prefix=(prefix+(c-'0'))%D;
  }
  printf("%d\n",(dp[0]+MOD-(prefix!=0))%MOD);
  return 0;
}
