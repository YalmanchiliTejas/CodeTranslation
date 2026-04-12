#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main() {
    int n;
    map<char, int> mp[50];
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) mp[i][s[j]]++;
    }
    string res = "";
    for (char a = 'a'; a <= 'z'; a++) {
        int num = 500, tmp;
        for (int i = 0; i < n; i++) {
            if (mp[i][a]) tmp = mp[i][a];
            else tmp = 0;
            num = min(num, tmp);
        }
        for (int i = 0; i < num; i++) res += a;
    }
    cout << res << endl;
}
