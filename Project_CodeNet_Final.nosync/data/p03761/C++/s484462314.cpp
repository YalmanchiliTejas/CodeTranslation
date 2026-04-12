#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> word(26, 50);
    for(int i = 0; i < N; i++) {
        string S;
        cin >> S;
        vector<int> word_tmp(26, 0);
        for(int j = 0; j < S.size(); j++) {
            word_tmp[S[j] - 'a']++;
        }
        for(int j = 0; j < 26; j++) {
            word[j] = min(word[j], word_tmp[j]);
        }
    }
    string result = "";
    for(int i = 0; i < 26; i++) {
        string str = string(word[i], 'a' + i);
        result += str;
    }
    cout << result << endl;
    return 0;
}