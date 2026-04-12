#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;

    string ans = "No";

    string tmp = to_string(S.at(0));

    for (int i = 0; i < S.length(); i++) {
        if(tmp != to_string(S.at(i))){
            ans = "Yes";
        }
    }
    
    
    cout << ans << endl;


    
    return 0;
}