#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
string S[60];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> S[i];

    int cnt[N][26];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < S[i].length(); j++) {
            cnt[i][S[i][j] - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        int min_i = 1.0e9;
        for (int j = 0; j < N; j++) {
            min_i = min(min_i, cnt[j][i]);
        }

        for (int j = 0; j < min_i; j++) {
            cout << (char)(i + (int)'a');
        } 
    }
    cout << endl;
    
    return 0;
}
