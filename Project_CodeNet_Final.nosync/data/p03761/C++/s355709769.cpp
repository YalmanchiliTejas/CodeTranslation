#include "bits/stdc++.h"

using namespace std;

int table[100];

int main(void) {
    int n; cin >> n;
    for (int i = 0; i < 100; i++) {
        table[i] = 51;
    }

    for (int i = 0; i < n; i++) {
        string t; cin >> t;
        for (char j = 0; j <= ('z' - 'a'); j++) {
            int cnt = 0;
            for (int k = 0; k < t.length(); k++) {
                if ((j + 'a') == t[k]) cnt++;
            }
            
            table[j] = min(table[j], cnt); 
        }
    }

    string res = "";

    for (int i = 0; i <= ('z' - 'a'); i++) {
        if (table[i] == 51) continue;
        for (int j = 0; j < table[i]; j++) {
            cout << (char)(i + 'a');
        }
    }

    cout << endl;

    return 0;
}