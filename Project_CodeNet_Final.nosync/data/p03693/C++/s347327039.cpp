#include <iostream>
using namespace std;
int main(void){
    int r,b,g;
    cin>>r>>b>>g;
    if((r*100+b*10+g)%4==0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
    
}