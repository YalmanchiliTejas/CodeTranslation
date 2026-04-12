#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int n;
    cin >> n;

    vector<int> c(26, 100);
    string s;
    for(int in=0;in<n;in++) {
        vector<int> ctmp(26, 0);
        cin >> s;
        for(int is=0;is<s.size();is++) {
            ctmp.at(s.at(is)-'a')++;
        }
        for(int i=0;i<26;i++) {
            c.at(i) = min(c.at(i), ctmp.at(i));
        }
    }

    char chara;
    for(int i=0;i<26;i++) {
        chara = i + 'a';
        for(int ic=0;ic<c.at(i);ic++) {
            cout << chara;
        }
    }
    cout << endl;
    return 0;
}
