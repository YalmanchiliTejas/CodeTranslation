#include <iostream>
#include <vector>
using namespace std;
#define MAX 50;

int main() {
    int n; cin >> n;
    vector<int> cnt(26);
    for (int i = 0; i < 26; i++) cnt[i] = MAX;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (char j = 'a'; j <= 'z'; j++) {
            int t = 0;
            for (int k = 0; k < s.size(); k++) {
                if (s[k] == j) t++;
            }
            cnt[j - 'a'] = min(cnt[j - 'a'], t);
        }
    }
    for (char i = 'a'; i <= 'z'; i++) {
        for (int j = 0; j < cnt[i - 'a']; j++) {
            cout << i;
        }
    }
    cout << endl;
}