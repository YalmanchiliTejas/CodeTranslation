#include <bits/stdc++.h>
using namespace std;

int main() {

    char c;
    cin >> c;

    string vowel = "aiueo";

    string ans = "consonant";

    for(auto k : vowel){
        if(c == k){
            ans = "vowel";
        }
    }

    cout << ans << endl;

    return 0;
}