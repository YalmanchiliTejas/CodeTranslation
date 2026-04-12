#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
int main() {
    string s;
    cin>>s;
    ll ca=0,cb=0;
    for(ll i=0;i<s.length();i++){
        if(s[i]=='A') ca++;
        if(s[i]=='B') cb++;
    }
    if(ca>=1 && cb>=1) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}