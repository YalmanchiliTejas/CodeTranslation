#include<cstdio>
using namespace std;
int main(){
  int h,w,g[8][8]={},l=0,flag=1;
  char s[8][10];
  scanf("%d %d",&h,&w);
  for(int i=0;i<h;i++)
    scanf("%s",s[i]);
  g[0][0]=1;
  for(int i=0;i<h;i++)
    for(;l<w;l++){
      if(l!=w-1&&g[i][l]&&s[i][l+1]=='#'){
        g[i][l+1]=1;
      }
      else if(i!=h-1&&g[i][l]&&s[i+1][l]=='#'){
        g[i+1][l]=1;
        break;
      }
    }
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      if(s[i][j]=='#'&&g[i][j]==0)
        flag=0;
  if(flag)
    printf("Possible\n");
  else
    printf("Impossible\n");
}
  