#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    int num,num1;
    cin>>s;
    num=0;
    num1=0;
    if(s[0]=='A'){
        num=1;
    }else if(s[0]=='B'){
        num1=1;
    }

    if(s[1]=='A'){
        num=1;
    }else if(s[1]=='B'){
        num1=1;
    }

    if(s[2]=='A'){
        num=1;
    }else if(s[2]=='B'){
        num1=1;
    }
    
    if(num==1 && num1==1){
        cout<<"Yes";
    }else {
        cout<<"No";
    }

    return 0;

}