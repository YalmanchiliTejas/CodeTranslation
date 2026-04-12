#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int N = 1e3 + 5;
const int M = 1e9 + 7;
int a[27];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < 26; i++) a[i] = M;
    while(n--) {
        string s;
        cin >> s;
        int temp[27];
        memset(temp, 0, sizeof(temp));
        for(int i = 0; i < s.size(); i++) {
            temp[s[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            a[i] = min(a[i], temp[i]);
        }
    }
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < a[i]; j++)
            cout << (char)('a' + i);
    }
    cout << "\n";
}
