#include<iostream>
#include<cstring>
#include<queue>
#include<map>
using namespace std;
int main(){
  int N,T,E,data[101],flg=0;
  int ok[10001][2];
  memset(ok,0,sizeof(ok));
  cin >> N >> T >> E;
  for(int i=0;i<N;i++){
    cin >> data[i];
    ok[data[i]][0]=1;
    ok[data[i]][1]=i+1;
  }
  for(int i=0;i<N;i++){
    for(int j=2;data[i]*j<10001;j++){
      ok[data[i]*j][0]=1;
      ok[data[i]*j][1]=ok[data[i]][1];
    }
  }
  for(int i=T-E;i<=T+E;i++){
    if(ok[i][0]==1){
      cout << ok[i][1] << endl;
      flg=1;
      break;
    }
  }
  if(flg==0)cout << -1 << endl;
}