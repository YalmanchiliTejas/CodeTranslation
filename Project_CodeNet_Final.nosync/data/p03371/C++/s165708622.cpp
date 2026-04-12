#include <bits/stdc++.h>
using namespace std;
int main(){
   int a,b,c,x,y;
   long long s=0;
   scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
   if(a+b > c*2){
        if(x<y){
            s += x*c*2;
            y -= x;
            if(y*c*2 < y*b) s += y*c*2;
            else s += y*b;
        }else{
            s += y*c*2;
            x -= y;
            if(x*c*2 < x*a) s += x*c*2;
            else s += x*a;
        }
   }else{
       s+=x*a+y*b;
   }
   printf("%lld",s);
}