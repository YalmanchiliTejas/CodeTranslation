#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> v(26, 114514);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector<int> now(26);
        for (auto c:s)now[c - 'a']++;
        for (int j = 0; j < 26; j++)v[j] = min(v[j], now[j]);
    }

    for (int i = 0; i < 26; i++)cout << string(v[i], 'a' + i);
    cout << endl;
    return 0;
}