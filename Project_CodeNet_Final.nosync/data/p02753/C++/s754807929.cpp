#include <bits/stdc++.h>
using namespace std;
const int INF=1001001001;
int main() {
    string s;cin>>s;
    if(s[0]=='A'&s[1]=='B'|s[1]=='A'&s[2]=='B')cout<<"Yes"<<endl;
    else if(s[0]=='B'&s[1]=='A'|s[1]=='B'&s[2]=='A')cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}