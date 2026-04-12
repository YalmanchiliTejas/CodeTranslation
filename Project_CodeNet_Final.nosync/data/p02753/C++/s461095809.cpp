#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    for (int i=1;i<s.size();++i){
        if (s[i]!=s[i-1]) {cout<<"Yes"; return 0;}
    }
    cout<<"No";
    return 0;
}


