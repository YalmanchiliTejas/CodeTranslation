#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,M;

    cin>>N>>M;
  vector<string> c(N);
  vector<int>a(N),b(M);
    for(int i = 0; i < N; i++){
        cin>>c[i];
      for(int j=0;j<M;j++){
      if(c[i][j]=='#'){
        a[i]=1;
        b[j]=1;
      }
      }
    }
      for(int i = 0; i < N; i++){
      for(int j=0;j<M;j++){
        if(a[i]!=1){
          break;
        }
      if(a[i]==1&&b[j]==1){
        cout<<c[i][j];
      }
        if(j==M-1){
          cout<<endl;
        }
      }
 
    }
}
