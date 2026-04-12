#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    bool flag=true;
    for(char x:s)if(x!=s[0])flag=false;
    if(flag)cout<<"No";
    else cout<<"Yes";
    return 0;
}