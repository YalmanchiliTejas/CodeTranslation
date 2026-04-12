#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,cnt=0;
  char s[100][100];
  char mp[100][100];
  for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
      s[i][j]=mp[i][j]='!';
    }
  }
  cin>>h>>w;
  int tate[h],yoko[w];
  for(int i=0;i<h;i++){
    tate[i]=0;
  }
  for(int i=0;i<w;i++){
    yoko[i]=0;
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>s[i][j];
      if(s[i][j]=='#') tate[i]=yoko[j]=1;
    }
  }
  int k=0,l=0;
  for(int i=0;i<h;i++){
    if(tate[i]==0) continue;
    for(int j=0;j<w;j++){
      mp[k][j]=s[i][j];
    }
    k++;
  }
  for(int i=0;i<w;i++){
    if(yoko[i]==0) continue;
    for(int j=0;j<k;j++){
      s[j][l]=mp[j][i];
    }
    l++;
  }
  for(int i=0;i<k;i++){
    for(int j=0;j<l;j++){
      cout<<s[i][j];
    }
    cout<<endl;
  }
  return 0;
}
