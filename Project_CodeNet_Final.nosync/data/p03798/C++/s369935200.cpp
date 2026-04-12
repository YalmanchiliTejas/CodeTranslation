#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n; string s;
    cin >> n >> s;
    vector<bool> v(n);
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            v[0] = i;
            v[1] = j;
            for(int k = 2; k < n; ++k) v[k] = v[k-1] ^ v[k-2] ^ (s[k-1] == 'x');
            if(v[0] == (v[n-1] ^ v[n-2] ^ (s[n-1] == 'x')) && (v[1] == v[0] ^ v[n-1] ^ (s[0] == 'x'))) {
                for(bool b : v) cout << (b?'W':'S');
                cout << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}