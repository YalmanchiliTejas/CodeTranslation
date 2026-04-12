#include <bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++) // repマクロ
#define all(v) v.begin(), v.end() // sort等の関数呼び出しを簡潔にする

using vi = vector<int>; // intの1次元の型に vi という別名をつける
using vvi = vector<vi>; // intの2次元の型に vvi という別名をつける

int main() {
    string S;
    cin >> S;

    if((S == "AAA") || (S == "BBB")){
        cout << "No" << endl;
    } else{
        cout << "Yes" << endl;
    }
return 0;
}