#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  long int x,y,min;
  scanf("%d %d %d %ld %ld",&a,&b,&c,&x,&y);
  long int mx=x>y?x:y;
  min=a*x+b*y;
  for(long int i=1;i<=mx;i++){
    long int sum=a*max(0L,x-i)+b*max(0L,y-i)+2*c*i;
    if(min>sum){
      min=sum;
    }
  }
  printf("%ld",min);
}
