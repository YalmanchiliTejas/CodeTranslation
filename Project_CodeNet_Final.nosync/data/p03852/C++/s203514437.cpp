#include <bits/stdc++.h>
using namespace std;
int main(){
    char c;
    cin >> c;
    switch(c) {
        case 'a':
        case 'i':
        case 'u':
        case 'e':
        case 'o':
            puts("vowel");
            break;
        default:
            puts("consonant");
            break;
    }
}
