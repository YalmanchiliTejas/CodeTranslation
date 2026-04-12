#include <bits/stdc++.h>
using namespace std;
int main(){
    int a=0,b;
    string s;
    cin>>s;
    for(int i=0;i<3;i++){
        if(s[i]=='A')
            a++;
        if(s[i]=='B')
            b++;
    }
        if(a==3||b==3)
            cout<<"No";
        else
            cout<<"Yes";

}
