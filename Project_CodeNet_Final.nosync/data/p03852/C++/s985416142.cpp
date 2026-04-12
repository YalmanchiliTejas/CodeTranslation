#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<string> s = {"a", "i", "u", "e", "o"};
    string c;
    cin >> c;
    for (int i = 0; i < s.size(); i++){
        if (c == s[i]){
            cout << "vowel" << endl;
            return 0;
        }
    }
    cout << "consonant" << endl;
    return 0;
}