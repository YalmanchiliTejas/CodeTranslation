#include <cstdio>
using namespace std;
int X,Y,Z,ans=0;
void solve(){
  ans=(X-Z)/(Y+Z);
  printf("%d\n",ans);
}
int main(){
  scanf("%d %d %d",&X,&Y,&Z);
  solve();
  return 0;
}
