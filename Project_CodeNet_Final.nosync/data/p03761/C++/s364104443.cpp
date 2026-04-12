#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int cc[26];
    fill(cc, cc+26, 1e9+1);
    for(int i = 0; i < n; i++) {
        for(char c = 'a'; c <= 'z'; c++) {
            cc[c-'a'] = min(cc[c-'a'], (int)count(v[i].begin(), v[i].end(), c));
        }
    }

    string ans;
    for(int i = 0; i < 26; i++) {
        ans += string(cc[i], (char)i + 'a');
    }
    cout << ans << endl;

    return 0;
}
