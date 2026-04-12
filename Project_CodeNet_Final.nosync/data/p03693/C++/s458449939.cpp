#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a,b,c,x=0;
    cin>>a>>b>>c;
    x=a*100+b*10+c;
    if(x%4==0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
