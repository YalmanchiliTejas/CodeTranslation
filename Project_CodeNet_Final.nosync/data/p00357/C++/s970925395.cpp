#include<cstdio>
#include<algorithm>
using namespace std;
int t[2][300005],d[300005];
int main(){
  int n,ma;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&d[i]);
    d[i] /= 10;
  }
  ma = 0;
  for(int i=0;i<n-1;i++){
    ma = max(ma-1,d[i]);
    t[0][i] = ma;
  }
  ma = 0;
  for(int i=n-1;i>0;i--){
    ma = max(ma-1,d[i]);
    t[1][i] = ma;
  }
  int j,ans = 0;
  j = 0;
  while(j < n-1 && t[0][j] != 0) j = j+t[0][j];
  if(j >= n-1) ans++;
  j = n-1;
  while(j > 0 && t[1][j] != 0) j = j-t[1][j];
  if(j <= 0) ans++;
  puts(ans==2?"yes":"no");
  return(0);
}

