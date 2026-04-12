#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for (int i = 0; i < (int)c; i++)
#define all(v) v.begin(), v.end()
const int inf = 1000000000; //10^9
using ll = long long;
using P = pair<int,int>;
//加算代入演算子は+=！！！！！
//int 2^31 10^9まで
int main() {
    char c;
    cin >> c;
    if(c == 'a' || c == 'e' ||  c == 'i' || c == 'o' || c == 'u') {
        cout << "vowel" << endl;
    }
    else cout << "consonant" << endl;
}