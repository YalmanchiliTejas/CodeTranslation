#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;
    vector<int> clist(26, 99);
    for (int i = 0; i < n; i++){
        vector<int> t(26, 0);
        string s;
        cin >> s;
        for (int j = 0; j < (int)s.size(); j++){
            t[s[j] - 'a']++;
        }
        for (int j = 0; j < 26; j++){
            clist[j] = min(clist[j], t[j]);
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < clist[i]; j++) cout << (char)('a'+i);
    }
    cout << endl;
    return 0;
}