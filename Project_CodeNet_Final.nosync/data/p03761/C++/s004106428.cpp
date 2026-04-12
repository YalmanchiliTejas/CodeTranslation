#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    int count[n][26] = {0};

    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<s.length(); j++) count[i][s[j]-'a']++;
    }

    for(int i=1; i<n; i++) {
        for(int j=0; j<26; j++) {
            count[0][j]=(count[0][j]<count[i][j])?count[0][j]:count[i][j];
        }
    }

    for(int i=0; i<26; i++) {
        for(int j=0; j<count[0][i]; j++) cout << (char)('a' + i);
    }

    cout << endl;

    return 0;
}

