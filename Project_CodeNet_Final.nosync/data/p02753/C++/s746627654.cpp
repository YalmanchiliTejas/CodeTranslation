#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;


bool test(const string &s,char a){
    for(auto i:s){
        if(i!=a){
            return false;
        }
    }
    return true;
}
int main()
{
    
    
    string s;
    cin>>s;
    if (test(s, 'A')||test(s, 'B')) {
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
    return 0;
}
