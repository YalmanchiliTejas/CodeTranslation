#include <iostream>
using namespace std;



int main(){
    int a,b,c,x,y;
    int sum;
    
    cin>>a>>b>>c>>x>>y;

    if((2*c)>=(a+b)) sum=a*x+b*y;

    if(2*c<=a&&2*c<=b){
        if(x>y){
            sum=2*c*x;
        }
        else{
            sum=2*c*y;
        }
    }

   else if(2*c<=b){
        if(x>y){
            sum=2*c*y+a*(x-y);
        }
        else{
            sum=2*c*y;
        }
    }

   else if(2*c<=a){
          if(x>y){
            sum=2*c*x;
        }
        else{
            sum=2*c*x+b*(y-x);
        }
    }

    else if(2*c>a && 2*c>b && 2*c<(a+b)){
        if(x>y){
             sum=2*c*y+a*(x-y);
        }
        else{
            sum=2*c*x+b*(y-x);
        }
    }
   cout<<sum<<endl;
   
}