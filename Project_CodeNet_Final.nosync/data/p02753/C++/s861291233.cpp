#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[3];
int main(){
    cin>>s;
    if(strcmp(s,"AAA")==0 || strcmp(s,"BBB")==0){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    return 0;
}