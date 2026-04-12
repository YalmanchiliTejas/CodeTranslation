#include <bits/stdc++.h>
using namespace std;

#define SIZE 40

int main() {
    string s;
    cin >> s;
    for(int i = 1; i < s.length(); i++) {
        if(s[i] == 'C' && s[i-1] == 'A') {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}