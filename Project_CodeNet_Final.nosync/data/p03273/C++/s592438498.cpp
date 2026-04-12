//B_Grid_Compression
#include <iostream>
#include <string>
using namespace std;

int main(){
  int n,m,i,j,count,hiku=0,herasu=0;
  int retu[101]={};
  char a[101][101];

  cin>>n>>m;
  for(i=0;i<n;i++){
    count=0;
    for(j=0;j<m;j++){
      cin>>a[i-hiku][j];
      if(a[i-hiku][j]=='.') count++;
      if(count==m) hiku++;
    }
  }
  //cout<<endl;
  
  for(i=0;i<m;i++){
    count=0;
    for(j=0;j<n-hiku;j++){
      if(a[j][i]=='.')
	count++;
      if(count==n-hiku){
	retu[i]=100;
      }
      //cout<<a[j][i];
    }
    // cout<<endl;
  }

  /*cout<<endl;
  for(i=0;i<m;i++) cout<<retu[i];
  cout<<endl;*/
  
  for(i=0;i<n-hiku;i++){
    for(j=0;j<m;j++){
      if(retu[j]==100) continue;
      cout<<a[i][j];
	}
    cout<<endl;
  }

  return 0;
}

