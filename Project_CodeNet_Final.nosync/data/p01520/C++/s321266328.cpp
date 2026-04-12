#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int N,T,E;
int main(){
  scanf("%d %d %d",&N,&T,&E);
  int res=-1;
  for(int i=0;i<N;i++){
    int x;
    scanf("%d",&x);
    //    printf("%d %d\n",T/x*x,(T/x+1)*x);
    if((T/x)*x >= T-E || (T/x+1)*x <= T+E) res=i+1;
  }
  printf("%d\n",res);
}