#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;  //これで"std::cout"が"cout"と書ける

//MACRO
typedef long long ll;                  //64bit以上を表現可能な型
#define INF 100000000                  //ほぼ無限
#define itn int                        //タイポ対策
#define all(x) (x).begin(), (x).end()  //sort(all(x))などとする
#define SZ(x) ((int)(x).size())        //size()簡略化
//repetition
#define FOR(i, p, b) for (int i = (p); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define repR(i, n) for (int i = n; i >= 0; i--)
//debug
#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" \<< " " << __FILE__ << endl;
template <class T>
bool chmax(T &a, const T &b) {  //aよりbが大きければaに代入
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {  //aよりbが小さければaに代入
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

//
//
//

int main() {
    char c;
    cin >> c;

    if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }

}