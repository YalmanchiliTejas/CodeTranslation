#include<iostream>
#include<string>
using namespace std;
int main(){
    int a,b;
    string str;
    char c;
    cin>>a>>str>>b;
    c=str[b-1];
    for(int i=0;i<str.size();i++){
        if(str[i]!=c)
            str[i]='*';
    }
    cout<<str<<endl;
    return 0;
}