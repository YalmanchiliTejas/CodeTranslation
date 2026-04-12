#include<iostream>
#include<math.h>
using namespace std;

int main(){
    double a,b,c,d=0,e=0;
    string s;
    cin>>s;
    if(s[0]==s[1] && s[1]==s[2]){cout<<"No"; return 0;}
    if(s[0]==s[2] || s[0]==s[1] || s[1]==s[2]){cout<<"Yes";return 0;}
    else{cout<<"No";}
    return 0;
}
