#include<iostream>
using namespace std;
#define df 0
typedef long int li;
li dc=0;
void rem(li& you,li& others,int n);
int main(){
  if(df) printf("*debug mode*\n");
  int n; cin >> n;
  li a[n],s=0;
  
  li y[n],oth[n],sum=0;
  for(int i=0;i<n;i++){
    dc+=df;
    cin >> y[i];
    s+=y[i];
    y[i]+=sum;
    oth[i]=0;
    rem(y[i],oth[i],n);
    if(df)printf("[%d,%d] ",y[i],oth[i]);
    sum+=oth[i];
  }
  if(df)printf("\n");
  while(sum){
    for(int i=0;i<n;i++){
      dc+=df;
      sum-=oth[i];
      y[i]+=sum;
      oth[i]=0;
      rem(y[i],oth[i],n);
      if(df)printf("[%d,%d] ",y[i],oth[i]);
      sum+=oth[i];
    }
    if(df)printf("\n");
  }
  for(auto& x: y) sum+=x;
  cout << s-sum <<"\n";

  if(df)printf("loop: %ld",dc);
}


void rem(li& you,li& others,int n){
  while(you>=n || others >=n){
    dc+=df;
    li m=min(you,others)-n+1;
    if(m>0){
      you-=m;
      others-=m;
    }
    others+=you/n;
    you%=n;
    you+=others/n*(n-1);
    others=others%n+others/n*(n-2);
  }
}

/// confirm df==0 ///