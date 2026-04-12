#include<bits/stdc++.h>
#define rep(i,a,n) for (int i = a; i < n; i++)
#define per(i,n,a) for (int i = n - 1; i >= a; i--)
using namespace std;

int main() {
    string s;
    cin >> s;
    rep(i, 0, s.size() - 1) {
        if(s[i] == 'A' && s[i + 1] == 'C'){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}