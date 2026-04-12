#include<iostream>
using namespace std;
#define df 0
#define rep(i,n) for(int i=0;i<(n);i++)
#define repa(i,a,n) for(int i=(a);i<(n);i++)
typedef long int li;

int main(){
  if(df) printf("*debug mode*\n");
  int n,m; cin >>n >>m;
  printf("%s",(n==m)?"Yes":"No");
}

/// confirm df==0 ///
