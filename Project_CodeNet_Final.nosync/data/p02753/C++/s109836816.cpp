#include <iostream>
using namespace std;
#include<stdlib.h>
#include<stdio.h>
int main(){
    string s;
    cin>>s;
    if(s[0]!=s[1]){
        cout<<"Yes\n";
    }
    else if(s[0]!=s[2]){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
    return 0;
}
