#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    char start=s.at(0);
    bool judge=false;
    for (char c: s){
        if (c!=start) {
            judge=true;
            break;
        }
    }
    if (judge) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}