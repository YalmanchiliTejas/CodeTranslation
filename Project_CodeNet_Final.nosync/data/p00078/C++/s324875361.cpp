#include<cstdio>
int n,a[20][20];
void solve(int i,int j,int c){
  if(n*n+1==c) return;
  if(i>n) return solve(1,j,c);
  if(j>n) return solve(i,1,c);
  if(i<1) return solve(n,j,c);
  if(j<1) return solve(i,n,c);
  if(!a[i][j]){
    a[i][j]=c;
    return solve(i+1,j+1,c+1);
  }
  if(a[i][j]) solve(i+1,j-1,c);
}
int main(void){
  for(;;){
    scanf("%d",&n);
    if(!n) break;
    for(int i=0;i<=n;i++){
      for(int j=0;j<=n;j++) a[i][j]=0;
    }
    solve(n/2+2,n/2+1,1);
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++) printf("%4d",a[i][j]);
      puts("");
    }
  }
}
