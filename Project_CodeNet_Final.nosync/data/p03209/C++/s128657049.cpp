#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
long long int a[60];//層の数
long long int p[60];//パティの数

long long int f(long long int N,long long int X){
  if(N==0)return 1;
  else if(X==1)return 0;
  else if(X<=1+a[N-1])f(N-1,X-1);
  else if(X==2+a[N-1])return p[N-1]+1;
  else if(X<=2+2*a[N-1])return p[N-1]+1+f(N-1,X-2-a[N-1]);
  else return 2*p[N-1]+1;
}

int main(void){
 int N;
 long long int X;
 cin>>N>>X;

 a[0]=1;
 p[0]=1;
 for(int i=1; i<=50; i++){
   a[i]=3+2*a[i-1];
   p[i]=1+2*p[i-1];
 }
 cout<<f(N,X)<<endl;
 return 0;
}