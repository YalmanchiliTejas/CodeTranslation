#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    char a,b,c;
    getline(cin,s);
    a=s[0];
    b=s[1];
    c=s[2];
    if(a==b&&a==c&&b==c)cout<<"No";
    else cout<<"Yes";
    return 0;
}