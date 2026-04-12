#include "bits/stdc++.h"
using namespace std;


int main() {
    char c;
    cin >> c;
    for(char ch: "aeiou") if(c == ch) return !printf("vowel\n");
    puts("consonant");
}