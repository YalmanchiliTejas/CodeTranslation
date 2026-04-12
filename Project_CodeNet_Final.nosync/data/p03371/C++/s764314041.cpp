#include<bits/stdc++.h>
using namespace std;

int main(void){
   long long A,B,C,X,Y;
   cin>>A>>B>>C>>X>>Y;
   long long result1=A*X+B*Y;
   long long result2=C*2*max(X,Y);
   long long temp=min(X,Y);
   X=X-temp;
   Y=Y-temp;
   long long result3=C*2*temp+A*X+B*Y;
   cout<<min(result1,min(result2,result3))<<endl;
   return 0;
}
