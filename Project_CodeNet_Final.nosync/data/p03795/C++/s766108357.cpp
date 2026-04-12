#include <iostream>
#include <string>

using namespace std;
int main(void){
    // Your code here!
    int s,t;
    cin>>s;
    t=(s/15)*200;
    if(s<15){
        cout<<s*800<<endl;
    }
    else{
        cout<<s*800-t<<endl;
    }
}
