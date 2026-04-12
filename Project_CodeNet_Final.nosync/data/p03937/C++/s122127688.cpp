#include <bits/stdc++.h>
using namespace std;

int main(){   
   int y,x,ans=0;
   char a;
   cin >> y >> x;
  
       for(int l=0;l<x*y;l++){
           cin >> a;
           if(a=='#'){
               ans++;
           }
       }
   
   if(ans==x+y-1){
       cout << "Possible" << endl;
   }else{
       cout << "Impossible" <<endl;
   }

}