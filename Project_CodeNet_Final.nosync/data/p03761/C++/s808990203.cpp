#include<iostream>
#include<string>
#define INF 1000
using namespace std;

int char_count[50][26];

int main() {
    int N;
    string S;
    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < 26; j++) char_count[i][j] = 0;
    for (int i = 0; i < N; i++) {
        cin >> S;
        for (int j = 0; j < S.length(); j++) {
            char_count[i][S[j] - 'a']++;
        }
    }
    string ans;
    for (int i = 0; i < 26; i++) {
        int min_count = INF;
        char moji;
        if (i == 0) moji = 'a';
        else if (i == 1) moji = 'b';
        else if (i == 2) moji = 'c';
        else if (i == 3) moji = 'd';
        else if (i == 4) moji = 'e';
        else if (i == 5) moji = 'f';
        else if (i == 6) moji = 'g';
        else if (i == 7) moji = 'h';
        else if (i == 8) moji = 'i';
        else if (i == 9) moji = 'j';
        else if (i == 10) moji = 'k';
        else if (i == 11) moji = 'l';
        else if (i == 12) moji = 'm';
        else if (i == 13) moji = 'n';
        else if (i == 14) moji = 'o';
        else if (i == 15) moji = 'p';
        else if (i == 16) moji = 'q';
        else if (i == 17) moji = 'r';
        else if (i == 18) moji = 's';
        else if (i == 19) moji = 't';
        else if (i == 20) moji = 'u';
        else if (i == 21) moji = 'v';
        else if (i == 22) moji = 'w';
        else if (i == 23) moji = 'x';
        else if (i == 24) moji = 'y';
        else moji = 'z';
        for (int j = 0; j < N; j++) {
            if (min_count > char_count[j][i]) min_count = char_count[j][i];
        }
        for (int j = 0; j < min_count; j++) {
            ans.push_back(moji);
        }
    }
    cout << ans << endl;
    return 0;
}