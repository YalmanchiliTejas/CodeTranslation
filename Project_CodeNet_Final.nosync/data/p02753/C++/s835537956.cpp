#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
int main(){
    string s; cin >> s;
    bool check = false;
    for(int i = 0; i < s.size() - 1; i++) {
        if(s[i] != s[i + 1]) {
            check = true;
            break;
        }
    }
    if(check) {
        cout << "Yes";
    }
    else{
        cout << "No" ;
    }
    return 0;
}