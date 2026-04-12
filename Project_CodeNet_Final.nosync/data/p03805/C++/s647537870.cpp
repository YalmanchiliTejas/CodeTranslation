#include<bits/stdc++.h>
using namespace std;
int Count_Path(vector<bool> data,int now,bool**field,const int n){
  int count=0;
  bool check=true;
  for(int i=0;i<n;i++){
    if(!data[i]){
      check=false;
      if(field[now][i]){
        data[i]=true;
        count+=Count_Path(data,i,field,n);
        data[i]=false;
      }
    }
  }
  if(check)return 1;
  return count;  
}
int main(void){
  int n=0;
  int m=0;
  cin>>n>>m;
  bool**field=new bool*[n];
  vector<bool>data(n);
  for(int i=0;i<n;i++){
    field[i]=new bool[n];
    data[i]=false;
    for(int j=0;j<n;j++){
      field[i][j]=false;
    }
  }
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    field[a-1][b-1]=true;
    field[b-1][a-1]=true;
  }
  data[0]=true;
  cout<<Count_Path(data,0,field,n)<<endl;
  return 0;
}