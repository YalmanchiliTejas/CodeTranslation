#include<iostream>
#include<algorithm>
using namespace std;

int main(){
   int A,B,AB,X,Y;
   cin>>A>>B>>AB>>X>>Y;

   int sum = AB*2*max(X,Y);

   int res = 0;

   if(X>=Y){
        if((A+B)*Y > AB*Y*2){
        res += AB*Y*2;
        res += A*(X-Y);
        }
        else res = A*X + B*Y;
    }

    else{
        if((A+B)*X > AB*X*2){
        res += AB*X*2;
        res += B*(Y-X);
        }
        else res = A*X + B*Y;
    } 

    res = min(res,sum);

    cout<<res<<endl;

}