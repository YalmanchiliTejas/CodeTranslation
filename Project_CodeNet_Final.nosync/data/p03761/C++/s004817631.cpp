#include"bits/stdc++.h"
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> S(n);
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }

    vector<int> min_hist(26, INT_MAX);
    for (int i = 0; i < n; i++) {
        vector<int> hist(26, 0);
        for (char c : S[i]) {
            hist[c - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            min_hist[j] = min(min_hist[j], hist[j]);
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < min_hist[i]; j++) {
            printf("%c", 'a' + i);
        }
    }
    printf("\n");
}