#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s[51];
    int count[51][26];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            count[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        cin >> s[i];
        int k = s[i].size();
        for(int j = 0; j < k; j++){
            count[i][s[i][j] - 'a']++;
        }
    }
    for(int j = 0; j < 26; j++){
        char alph = 'a' + j;
        int ansj = 100;
        for(int i = 0; i < n; i++){
            ansj = min(ansj, count[i][j]);
        }
        for(int i = 0; i < ansj; i++){
            cout << alph;
        }
    }
}