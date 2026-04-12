#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;
string cell[100];
int n,m;
int main(){
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++)
    cin>>cell[i];
  int r = 0;
  int c = 0;
  while(r<n){
    while(c<m){
      if(cell[r][c]=='#'){
        cell[r][c] = '.';
        if(c<m && cell[r][c+1]=='#') c++;
        else if(c==m-1) c= m-1;
        else break;
      }
      else break;
    }
    r++;
  }
  int cnt = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      //cout<<cell[i][j]<<" ";
      if(cell[i][j]=='#') cnt++;
    }
    //cout<<endl;
  }
  if(cnt>0) cout<<"Impossible"<<endl;
  else cout<<"Possible"<<endl;
  return 0;
}
