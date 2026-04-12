#include <bits/stdc++.h>
using namespace std;
 
int main(){
   int a,b,c,x,y;
   cin >> a >> b >> c >> x >> y;
   int min = 0;
   if(a+b >= 2*c){
       if(x > y and a < 2*c){
           min += 2*c*y;
           min += (x-y)*a;
       }else if(x > y and a > 2*c){
           min += 2*c*x;
       }else if(x < y and b > 2*c){
           min += 2*c*y;
       }else{
           min += 2*c*x;
           min += (y-x)*b;
       }
   }else{
       min = a*x + b*y;
   }
   cout << min << endl;
    
}
 