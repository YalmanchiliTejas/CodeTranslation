#include <iostream>
#include <string>
using namespace std;
int main(void){
    // Your code here!
    int x,y,a,r,g,b;
    cin>>r>>g>>b;
    x=r*100+g*10+b;
    if(x%4==0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
