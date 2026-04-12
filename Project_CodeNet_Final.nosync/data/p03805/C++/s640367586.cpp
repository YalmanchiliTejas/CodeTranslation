#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<functional>
#include<vector>
#include<math.h>
using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  int data[M][2];
  for(int i=0;i<M;i++){
    cin>>data[i][0]>>data[i][1];
  }
  //N個の都市を並べ替えて、それが通れるかチェック
  int  order[N];
  for(int i=1;i<=N;i++) order[i-1]=i;
  int ans=0;
  do{ //チェック
    for(int i=0;i<N-1;i++){
      bool judge=false;
      for(int j=0;j<M;j++){
     	 if((order[i]==data[j][0]&&order[i+1]==data[j][1])||(order[i]==data[j][1]&&order[i+1]==data[j][0])){
          judge=true;
          break;
         }
      }
      if(!judge)  break;
      if(i==N-2) ans++;
    }
  }while(next_permutation(order+1, order+N));
    
  cout<<ans<<endl;

}