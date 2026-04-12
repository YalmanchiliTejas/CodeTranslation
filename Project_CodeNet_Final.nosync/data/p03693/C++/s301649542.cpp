#include <iostream>
using namespace std;
int main(void){
    int r,g,b,T;
    cin>>r>>g>>b;
    T=r*100+g*10+b;
    if(T%4==0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    
    return 0;
}
