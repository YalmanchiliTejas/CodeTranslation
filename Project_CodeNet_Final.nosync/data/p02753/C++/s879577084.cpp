#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5;
int a,b,c;
string s;
int main(){
    cin>>s;
    int ok1=0,ok2=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='A')ok1=1;
        if(s[i]=='B')ok2=1;
    }
    if(ok1==1&&ok2==1){
        cout<<"Yes";
        return 0;
    }
    cout<<"No";
    return 0;
}

