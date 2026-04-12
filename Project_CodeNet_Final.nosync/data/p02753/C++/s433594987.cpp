#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    if(count(s.begin(),s.end(),'A')==3||count(s.begin(),s.end(),'B')==3)cout <<"No";
    else cout <<"Yes";
}