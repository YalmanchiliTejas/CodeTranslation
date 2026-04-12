#include <bits/stdc++.h>
using namespace std;

int main(){
   int a, b, c, x, y, am, bm, cm;
   cin >> a >> b >> c >> x >> y;
   am = x;
   bm = y;
   cm = 0;
   int q = (a*am)+(b*bm)+(c*cm);
   while(am > 0 || bm > 0){
     if (q > (a*am)+(b*bm)+(c*cm)) {
       q = (a*am)+(b*bm)+(c*cm);
     }
    if (am>0){am--;}
    if (bm>0){bm--;}
     cm += 2;
   }
   if (q > (a*am)+(b*bm)+(c*cm)) {
     q = (a*am)+(b*bm)+(c*cm);
   }
   cout << q << endl;

}