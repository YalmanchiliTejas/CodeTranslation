#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
  int n,a,sum,ma,mi;
  while(scanf("%d",&n),n){
    sum = 0;
    ma = 0;
    mi = 1001;
    for(int i=0;i<n;i++){
      scanf("%d",&a);
      sum += a;
      ma = max(ma,a);
      mi = min(mi,a);
    }
    sum -= ma+mi;
    printf("%d\n",sum/(n-2));
  }
  return (0);
}