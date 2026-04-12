#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    string s;
    cin >> s;
    if(s[0] == s[1] && s[1] == s[2]){
        cout << "No" << endl;
    } else {
        cout << "Yes " << endl;
    }
    return 0;
}
