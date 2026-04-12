#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;
    bool a = false, b = false;
    for(char& c: s){
        if(c=='A') a = true;
        if(c=='B') b = true;
    }
    if(a&b) cout << "Yes\n";
    else cout << "No\n";
}