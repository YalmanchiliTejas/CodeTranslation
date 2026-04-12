#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // input
    char c;
    cin >> c;
    vector<char> vowels{'a', 'i', 'u', 'e', 'o'};
    bool hit = false;
    for (const auto& v:vowels) {
        if (v == c){
            cout << "vowel" << endl;
            return 0;
        } 
    }
    cout << "consonant" << endl;;
    return 0;
}
