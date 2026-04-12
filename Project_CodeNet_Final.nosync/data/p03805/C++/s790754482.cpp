#include<bits/stdc++.h>
using namespace std;

int temp[10][10] = {}, N, M;

int foo(int n,int coun,int bb[]){//cout<<coun<<" "<<n<<endl;
    if(coun == N)return 1;
    int tee[10][10], ans =0, aa[10]={},C=0;
    for(int i = 1; i <= coun;i++){aa[bb[i]]=1;}
  for(int i = 1; i <= N; i++){
    if(aa[i]==1)continue;
    //tee[n][i]=1;
    bb[coun+1]=i;
    if(temp[n][i])ans += foo(i,coun+1,bb);
    
    //tee[n][i]=0;
    
  }
  //if(ans==0)return 0;
  return ans;
}

int main(){
  int a, b, te[10][10]={}, bb[10] = {};
  cin>>N>>M;
  te[1][1] = 1;bb[1]=1;
  for(int i = 0; i < M; i++){
    cin>>a>>b;
    temp[a][b]=1;
    temp[b][a]=1;
  }

  cout<<foo(1,1,bb)<<endl;

  return 0;
}
