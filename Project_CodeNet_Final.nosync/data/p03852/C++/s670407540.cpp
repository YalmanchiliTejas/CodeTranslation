#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    string s;
    cin >> s;
    set<std::string> se = {"a","i","u","e","o"};
    if (se.count(s) > 0) {
        cout << "vowel" << endl;
    }
    else{
        cout << "consonant" << endl;
    }



}
