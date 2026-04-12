#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int cnt1=0, cnt2=0;
    for(int i=0;i<3;++i){
        if(s[i]=='A')++cnt1;
        else ++cnt2;
    }

    if(cnt1==3||cnt2==3)cout<<"No";
    else cout<<"Yes";

    return 0;
}
