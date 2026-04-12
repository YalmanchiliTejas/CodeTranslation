#include<bits/stdc++.h>
using namespace std;

int main(void){
   int A,B,C,X,Y;
   cin>>A>>B>>C>>X>>Y;
   int sum_1;
   sum_1=C*min(X,Y)*2;
   if(X==min(X,Y)){
       sum_1+=B*(Y-min(X,Y));
   }else{
       sum_1+=A*(X-min(X,Y));
   }
   int sum_2=A*X+B*Y;
   int sum_3=C*max(X,Y)*2;
   cout<<min(min(sum_1,sum_2),sum_3)<<endl;
   return 0;
}

