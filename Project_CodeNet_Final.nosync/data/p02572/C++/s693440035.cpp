#include <bits/stdc++.h>
using namespace std;

int64_t Q=1000000007;

int64_t jyo(int64_t x,int64_t y){
  int64_t H=y; //ここから
       int64_t a=1,b=0,c=1;
       while(H>0){
         a*=2;
         if(H%a!=0){
           H-=a/2;
           int64_t d=x;
           for(int j=0;j<b;j++){
            d=d*d;
             d=d%Q;
          }
           c=c*d;
          c=c%Q;
         }
        b++;
      } //ここまで
  return c;
}



int main() {
  int N;
  cin>>N;
  int64_t M=0,Z=0;
  for(int i=0;i<N;i++){
    int64_t a;
    cin>>a;
    Z+=(Q*Q-a*a);
    Z%=Q;
    M+=a;
    M%=Q;
  }
  Z+=((M*M)%Q);
  Z%=Q;
  Z*=jyo(2,Q-2);
  Z%=Q;
  cout<<Z<<endl;
}