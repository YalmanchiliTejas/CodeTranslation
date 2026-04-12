#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(26, 1000000);

    for(int i = 0; i < n; i++) {
        string S;
        cin >> S;
        vector<int> b(26);
        for(int j = 0; j < S.length(); j++) {
            b[S[j] - 'a']++;
        }
        for(int j = 0; j < 26; j++) {
            a[j] = min(a[j], b[j]);
        }
    }

    for(int i = 0; i < 26; i++) {
        if(a[i] == 1000000) a[i] = 0;
        for(int j = 0; j < a[i]; j++) {
            cout << char(i + 'a');
        }
    }

    cout << endl;
}