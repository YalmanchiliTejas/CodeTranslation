#include <bits/stdc++.h> 
using namespace std; 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void vowelOrConsonant(char x) { 
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') 
        cout << "vowel" << endl; 
    else
        cout << "consonant" << endl; 
}
int main(void) {
    io;
    char c; cin >> c;
    vowelOrConsonant(c);
    return 0; 
} 
