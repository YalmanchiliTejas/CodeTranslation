#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M,a,b;
  cin>>N>>M;
  
  int P[10][10];//隣接行列
  int F[10];//訪問フラグ F[0] - F[N-1]
  
  //隣接行列初期化
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      P[i][j]=0;
    }
  }
  
  //隣接データ入力
  for(int i=0;i<M;i++){
    cin>>a>>b;
    a--;
    b--;
    P[a][b]=1;
    P[b][a]=1;
  }
  
  vector<int>vec(N-1,0);//* N-1 か　Nか
  for(int i=0;i<N-1;i++){
    vec.at(i)=i+1;
  }
  
  int ans=0;
   do {
    /*for(int k=0;k<N-1;k++){
      cout<<vec.at(k)<<endl;
    }*/
      
    //F初期化
    for(int i=0;i<N-1;i++){
      F[i]=0;
    }
    
    //パス確認
    if(P[0][vec.at(0)]==0){
      //cout<<"$"<<vec.at(0)<<endl;
      continue;
    }
    else{
      F[0]=1;
    }
    
    for(int i=0;i<N-2;i++){
      if(P[vec.at(i)][vec.at(i+1)]==1){ 
        F[i+1]=1;
        continue;
      }
      else{
        break;
      }
    }
    
    //全パス確認　ans++
    int flag=1;
    for(int i=0;i<N-1;i++){
      if(F[i]==0){
        //cout<<i<<"#"<<vec.at(0)<<endl;
        flag=0;
        break;
      }
    }
    if(flag){
      ans++;
    }
  } 
  while (next_permutation(vec.begin(), vec.end()));
  
  cout<<ans<<endl;
  return 0;
}