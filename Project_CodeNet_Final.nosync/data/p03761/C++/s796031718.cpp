#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;
const int inf = 1000000000; //10^9
const ll MOD = 1e9 + 7;
//加算代入演算子は+=！！！！！
//int 2^31 10^9まで
int main()
{
    string s[60] = {}; //string型のs。要素数60。初期値は空。
    int n; 
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i]; //文字列の入力を文字列Sに代入
    }
    string ans;
    for (char c = 'a'; c <= 'z'; c++) //a~zまでループ
    {
        int small = inf;
        for (int i = 0; i < n; i++) //文字列分ループ
        {
            int cnt = 0;
            for (int j = 0; j < s[i].length(); j++) //各文字列の長さ分ループ
            {
                if (s[i][j] == c) //各文字列の個々の文字とa~zを比較
                    cnt++; //一緒ならカウンタを加算
            }
            small = min(small, cnt); //各アルファベットの出現数の最小値を取得
        }
        for (int i = 0; i < small; i++)
        {
            ans += c; //各アルファベットの最小値の出現数をansに代入。a~zのループだから並び替えは不要。
        }
    }
    cout << ans << endl;

    return 0;
}