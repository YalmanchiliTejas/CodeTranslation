#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i < (n); ++i)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; }}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; }}

using namespace std;

int main() {
    string s;
    cin >> s;

    char temp = s[0];
    for (int i = 1; i < s.size(); ++i) {
        if (temp != s[i]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}