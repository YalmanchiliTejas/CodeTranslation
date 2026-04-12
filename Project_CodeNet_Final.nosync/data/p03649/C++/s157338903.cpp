#include<iostream>
using namespace std;
#define df 0
typedef long int li;
void rem(li x,li& you,li& others,int n);
int main(){
  if(df) printf("*debug mode*\n");
  int n; cin >> n;
  li a[n],s=0;
  for(auto& x:a){
    cin >> x;
    s+=x;
  }
  
  li y[n],oth[n];
  for(int i=0;i<n;i++){
    y[i]=oth[i]=0;
  }
  bool flag;
  do{
    li sum=0;
      for(int i=0;i<n;i++){
	rem(a[i],y[i],oth[i],n);
	sum+=oth[i];
      }
    flag=false;
    li amin=sum+y[0];
    for(int i=0;i<n;i++){
      a[i]=sum+y[i]-oth[i];
      if(a[i]>=n)flag=true;
      if(a[i]<amin)amin=a[i];
      y[i]=oth[i]=0;
      if(df)printf("%ld ",a[i]);
    }
    if(df)printf("\n");
    if(amin>=n){
      amin-=n-1;
      for(auto& x:a){
	x-=amin;
	if(df)printf("%ld ",x);
      }
      if(df)printf("\n");
    }
    sum=0;
  }while(flag);
  li sum=0;
  for(auto& x:a) sum+=x;
  printf("%ld",s-sum);
}


void rem(li x,li& you,li& others,int n){
  you+=x%n;
  x/=n;
  others+=x%n;
  x/=n;
  if(x){
    rem(x,you,others,n);
  }
}

/// confirm df==0 ///
