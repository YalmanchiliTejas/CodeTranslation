#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    string result = "consonant";
    
    if(S == "a" || S == "e" || S == "i" || S == "o" || S == "u")
    {
        result = "vowel";
    }
    
    cout << result << endl;
}
