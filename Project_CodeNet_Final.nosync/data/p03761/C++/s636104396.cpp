#include <iostream>
#include <map>
#include <string>

using namespace std;

int n;
map<char, int> mp;

void solve() {
    string s; cin >> s;
    for(int j = 0; j < s.size(); j++) {
        mp[s[j]]++;
    }
    for(int i = 1; i < n; i++) {
        map<char, int> tmp;
        cin >> s;
        for(int j = 0; j < s.size(); j++) {
            tmp[s[j]]++;
        }
        for(char k = 'a'; k <= 'z'; k++) {
            if(mp[k] >= tmp[k]) mp[k] = tmp[k];
        }
    }
    for(char k = 'a'; k <= 'z'; k++) {
        for(int i = 0; i < mp[k]; i++) {
            cout << k ;
        }
    }
    cout << endl;
    
}

int main() {
    cin >> n;
    solve();
}