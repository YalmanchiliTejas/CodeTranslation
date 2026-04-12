#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; string s;
    cin >> n;
    cin >> s;
    cin >> k;

    k --;
    for(auto& i : s) {
        if(i != s[k])
            i = '*';
    }

    cout << s << endl;
}
