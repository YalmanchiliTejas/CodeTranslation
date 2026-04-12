#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
   int a,b,c,x,y;
   cin >> a >> b >> c >> x >> y;
   if(a+b <= 2*c){
       cout << a*x+b*y << endl;
   }else{
       if(x >= y){
           if(a <= 2*c){
               cout << y*2*c + (x-y)*a << endl;
           }else{
               cout << x*2*c << endl;
           }
       }else{
           if(b <= 2*c){
               cout << x*2*c + (y-x)*b << endl;
           }else{
               cout << y*2*c << endl;
           }
       }
   }
   return 0;
}