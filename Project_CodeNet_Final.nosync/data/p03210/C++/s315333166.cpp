#include<iostream>
#include<string>
using namespace std;

int main(void){
    int y;
    string a;
    cin>>y;

    if(y==3 || y==5 || y==7){
        a="YES";
    }else a="NO";

    cout<<a<<endl;

    return 0;
}