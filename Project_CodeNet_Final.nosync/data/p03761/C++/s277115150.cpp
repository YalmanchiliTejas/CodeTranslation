#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> S(n, "");
    for (auto &s: S) cin >> s;
    vector<int> freq_min(26, 100);
    for (auto &s: S){
        vector<int> freq(26, 0);
        for (auto c: s) freq[c - 'a'] += 1;
        for (int i = 0; i != 26; ++i) freq_min[i] = min(freq_min[i], freq[i]);
    }
    for (int i = 0; i != 26; ++i){
        char c = 'a' + i;
        for (int j = 0; j < freq_min[i]; ++j){
            cout << c;
        }
    }
    cout << endl;
    return 0;
}