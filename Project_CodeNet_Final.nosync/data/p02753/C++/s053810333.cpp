#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int ca=0,cb=0;
    for(int i=0;i<3;i++){
        if(s[i]=='A')
        ca++;
        if(s[i]=='B')
        cb++;
    }
    if(ca==3 || cb==3)
    cout<<"No";
    else
    cout<<"Yes";
    
    return 0;
}
