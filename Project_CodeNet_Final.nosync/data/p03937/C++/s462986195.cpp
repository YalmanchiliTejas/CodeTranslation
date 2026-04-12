#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int W,H;
char m[9][9];
int main(){
  int c=0;
  scanf("%d %d",&H,&W);
  for(int i=0;i<H;i++)scanf("%s",&m[i]);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(m[i][j]=='#')c++;
    }
  }
  if(c==W+H-1)printf("Possible\n");
  else printf("Impossible\n");
  return 0;
}
