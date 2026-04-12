#include <iostream>
#include <string>

using namespace std;

const int K = 26;

void count_char(int *a, string s) {
    for (int i = 0; i < K; i ++) {
        a[i] = 0;
    }
    for (int i = 0; i < s.size(); i ++) {
        a[s[i] - 'a'] ++;
    }
}

int main() {
    int n;
    string S[50];
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> S[i];
    }
    int count[K];
    for (int i = 0; i < K; i ++) {
        count[i] = 999999;
    }
    for (int i = 0; i < n; i ++) {
        int count2[K];
        count_char(count2, S[i]);
        for (int j = 0; j < K; j ++) {
            if (count2[j] < count[j]) {
                count[j] = count2[j];
            }
        }
    }
    for (int i = 0; i < K; i ++) {
        for (int j = 0; j < count[i]; j ++) {
            cout << (char)('a' + i);
        }
    }
    cout << endl;
}