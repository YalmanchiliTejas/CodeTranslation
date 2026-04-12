#include <bits/stdc++.h>
using namespace std;

int main(void){

   int X,Y,Z,sum=0,ans=1;
   cin >> X >> Y >> Z;
   
   sum += (Y + 2 * Z);
   while(1){
       if(sum + (Y + Z) > X) break;
       sum += (Y + Z);
       ans++;
   }
   cout << ans << endl;
}