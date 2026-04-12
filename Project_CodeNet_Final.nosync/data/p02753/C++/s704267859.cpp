#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    bool ans = false;

    if(s[0] == 'A'){
        if(s[1] == 'B' || s[2] == 'B') ans = true;
    }
    else{
        if(s[1] == 'A' || s[2] == 'A') ans = true;
    }
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}