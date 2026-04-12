#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
    int n;cin>>n;
    map<char, int> chs;
    // 最初の文字列を代入する
    string S;cin>>S;
    for (int i = 0; i < S.size(); i++) {
        char s = S[i];
        if (chs.find(s) != chs.end()) chs[s] += 1;
        else chs[s] = 1;
    }
    // S2以降の処理を行う
    for (int i = 1; i < n; i++) {
        string S;cin>>S;
        for (map<char, int>::iterator it = chs.begin(); it != chs.end(); ++it) {
            int cnt = count(S.begin(), S.end(), it->first);
            chs[it->first] -= max(it->second - cnt, 0);
        }
    }
    // 結果を出力する
    for (map<char, int>::iterator it = chs.begin(); it != chs.end(); ++it) {
        for (int i = 0; i < it->second; i++) {
            cout << it->first;
        }
    }
    cout << endl;
    return 0;
}