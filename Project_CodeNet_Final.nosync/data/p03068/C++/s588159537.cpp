#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int n,k;
    string s;
    cin >> n >> s >> k;
    char c = s[k-1];
    rep(i,n) {
        if(s[i] != c) {
            s[i] = '*';
        }
    }
    cout << s << "\n";
    return 0;
}