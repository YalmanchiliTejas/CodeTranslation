#include<cstdio>
#include<cstring>
using namespace std;
int main(){
  char s[101][101];
  int h,w,hh,ww,flag,g[100]={},g2[100]={};
  scanf("%d %d",&h,&w);
  for(int i=0;i<h;i++)
    scanf("%s",s[i]);
  hh=h;
  ww=w;
  for(int i=0;i<h;i++){
    flag=1;
    for(int j=0;j<w;j++)
      if(s[i][j]=='#')
        flag=0;
    g2[i]=flag;
  }
  for(int i=0;i<ww;i++){
    flag=1;
    for(int j=0;j<hh;j++)
      if(s[j][i]=='#')
        flag=0;
    g[i]=flag;
  }
  for(int i=0;i<h;i++){
    if(g2[i]==0){
      for(int j=0;j<w;j++)
        if(g[j]==0)
          printf("%c",s[i][j]);
      printf("\n");
    }
  }
}