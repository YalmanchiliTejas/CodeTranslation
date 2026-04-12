#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int f=0,p=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='A'){
            f++;
        }
        if(s[i]=='B')p++;
    }
    if(f==3||p==3)cout<<"No";
    else cout<<"Yes";
 
}