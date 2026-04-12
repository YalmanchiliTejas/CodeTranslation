#include<bits/stdc++.h>
using namespace std;

int main(void){
   int X,Y,Z;
   cin>>X>>Y>>Z;
   for(int i=1;;i++){
      int result=Y*i+Z*(i+1);
      if(result>X) {
         cout<<i-1<<endl;
         return 0;
      }
   }
   return 0;
}

