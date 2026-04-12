#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main(){
    int n,k;
    string s;
    cin >> n >> s >> k;
    char c = s[k - 1];
    for (int i = 0; i < n; i++) {
        if (s[i] != c)
            s[i] = '*';
    }
    cout << s << endl;
}