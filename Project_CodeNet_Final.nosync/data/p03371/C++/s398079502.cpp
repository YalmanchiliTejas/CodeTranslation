#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;

int main(void){

  
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int sum=0;
  int sum1=0;

    if(x==0 || y==0){
        sum=a*x+b*y;
    }else{
      if(a+b>2*c){
          if(x<y){
              sum=x*2*c+(y-x)*b;
              sum1=2*c*y;
              if(sum1<sum)sum=sum1;
          }else{
              sum=y*2*c+(x-y)*a;
              sum1=2*c*x;
              if(sum1<sum)sum=sum1;
          }
      }else{
          sum=a*x+b*y;
      }
  }
  cout<<sum<<endl;

}