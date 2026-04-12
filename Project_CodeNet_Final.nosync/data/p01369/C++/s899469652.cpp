#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <locale>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int solve(string s) {
    bool flag;
    int ans = 0;
    int position[s.size()];
    for (int i = 0; i < s.size(); i++) {
        switch (s[i]) {
            case 'y':
            case 'u':
            case 'i':
            case 'o':
            case 'p':
            case 'h':
            case 'j':
            case 'k':
            case 'l':
            case 'n':
            case 'm':
                if (i == 0) flag = true;
                position[i] = 1;
                break;

            default:
                if (i == 0) flag = false;
                position[i] = 2;
                break;
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (flag) {
            if (position[i] == 2) {
                ans++;
                flag = false;
            }
        } else {
            if (position[i] == 1) {
                ans++;
                flag = true;
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    string nyuuryoku;
    vector<int> ans;
    while (1) {
        cin >> nyuuryoku;
        if (nyuuryoku == "#") break;
        ans.push_back(solve(nyuuryoku));
    }
    for (int i : ans) {
        cout << i << endl;
    }
    return 0;
}
/*
1.文字列を読み込む
2.先頭の文字が右にあるのか左にあるのか判断
3.右ならtrue左ならfalseをフラッグに入れる
4.フラッグを使い左右が変わったか判断
5.カウントを返す
*/
