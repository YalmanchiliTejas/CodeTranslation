#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,k;
    string s;
    cin>>a>>s>>k;
    char m=s.at(k-1);
    for(char c:s){
        if(c!=m) cout<<"*";
        else cout<<c;
    }
    cout<<"\n";
}