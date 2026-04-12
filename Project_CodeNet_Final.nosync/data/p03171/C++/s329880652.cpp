#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  vector<int> A(N);
  for(int &i:A)
    cin>>i;
  vector<vector<vector<int>>> B(N+1,vector<vector<int>>(N+1,vector<int>(2,0)));
  for(int i=0;i<N;i++){
    for(int j=0;j<N-i;j++){
      if(j+i==0){
        B[j][j+i][0]=B[j+1][j+i][1]+A[j+i];
        B[j][j+i][1]=B[j+1][j+i][0]-A[j+i];
      }else if(j==N-1){
        B[j][j+i][0]=B[j][j+i-1][1]+A[j+i];
        B[j][j+i][1]=B[j][j+i-1][0]-A[j+i];
      }else{
        B[j][j+i][0]=max(B[j][j+i-1][1]+A[j+i],B[j+1][j+i][1]+A[j]);
        B[j][j+i][1]=min(B[j][j+i-1][0]-A[j+i],B[j+1][j+i][0]-A[j]);
      }
    }
  }
  cout<<B[0][N-1][0]<<endl;
}