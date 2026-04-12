#include <iostream>
using namespace std;
int main(void){
    int a,x,y;
    
    cin >>a;
    
    x=a*800;
    
    if(a>=15){
        y=(a/15)*200;
    }                
    else{
        y=0;
    }
    cout <<x-y;
    
    return 0;
    
}