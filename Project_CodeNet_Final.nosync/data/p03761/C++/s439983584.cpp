#include<iostream>
#include<map>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    scanf("%d", &n);

    string s[n];
    map<char, int> mp;
    cin >> s[0];
    for (int j = 0; j < s[0].size(); j++) mp[s[0][j]]++;

    for (int i = 1; i < n; i++) {
        cin >> s[i];
        map<char, int> mp_tmp;
        for (int j = 0; j < s[i].size(); j++) mp_tmp[s[i][j]]++;
        for (char c = 'a'; c <= 'z'; c++) mp[c] = min(mp[c], mp_tmp[c]);
    }

    for (char c = 'a'; c <= 'z'; c++) {
        for (int i = 0; i < mp[c]; i++) printf("%c", c);
    }
    printf("\n");

    
}