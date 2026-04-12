//
// Created by Tzyark on 2018/10/10.
//
#include <iostream>
#include <set>
using namespace std;
int main() {
    set<char> vowel;
    vowel.clear();
    vowel.insert('a');
    vowel.insert('e');
    vowel.insert('i');
    vowel.insert('o');
    vowel.insert('u');
    char c;
    cin >> c;
    cout << (vowel.count(c) > 0 ? "vowel" : "consonant");
    return 0;
}
