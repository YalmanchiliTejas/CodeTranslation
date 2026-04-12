#include<bits/stdc++.h>
using namespace std;
int main(){
	int h,w;cin>>h>>w;
  vector<vector<char > >mat(h,vector<char >(w,'.'));
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      cin>>mat[i][j];
  //note which rows have complete 
  vector<int >rows(h,0);
  vector<int >cols(w,0);
  for(int i=0;i<h;i++){
  	int times=0;
    for(int j=0;j<w;j++)if(mat[i][j]=='.')times++;
    if(times==w)rows[i]=1;
  }
  for(int j=0;j<w;j++){
  	int times=0;
    for(int i=0;i<h;i++)if(mat[i][j]=='.')times++;
    if(times==h)cols[j]=1;
  }
  for(int i=0;i<h;i++){
  	if(rows[i]==1)continue;
    for(int j=0;j<w;j++)if(cols[j]!=1)cout<<mat[i][j];
    cout<<'\n';
  }
}