#include<bits/stdc++.h>
using namespace std;
#define int long
using pi=pair<int,int>;
signed main(){
    string s;
    cin>>s;
    if (s[0] == s[1] && s[1] == s[2]) cout << "No";
    else
        cout << "Yes";
}