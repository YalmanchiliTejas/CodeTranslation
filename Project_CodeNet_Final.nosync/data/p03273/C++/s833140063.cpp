#include<bits/stdc++.h>
using namespace std;
int i,j,n,a[100],b[100],c,d,h,w,k,l;
char s[100][100];
int main(){
  for(cin>>h>>w;i<h;i++)for(j=0;j<w;j++)cin>>s[i][j];
  for(i=0;i<h;i++){
    for(c=0,j=0;j<w;j++){
      if(s[i][j]=='.')c++;
    }
    if(c==w){
      for(k=i;k<h;k++){
        for(l=0;l<w;l++){
          s[k][l]=s[k+1][l];
        }
      }
      i--;
      h--;
    }
  }

  for(i=0;i<w;i++){
    for(c=0,j=0;j<h;j++){
      if(s[j][i]=='.')c++;
    }
    if(c==h){
      for(k=i;k<w;k++){
        for(l=0;l<h;l++){
          s[l][k]=s[l][k+1];
        }
      }
      i--;
      w--;
    }
  }

  for(i=0;i<h;i++){
    for(j=0;j<w;j++)cout<<s[i][j];
    cout<<endl;
  }

}