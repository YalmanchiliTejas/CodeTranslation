#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    bool a=false;bool b=false;
    char c;
    for(int i=0;i<3;i++){
        cin>>c;
        if(c=='A'){
            a=true;
        }else{
            b=true;
        }
    }
    if(a&&b){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}
