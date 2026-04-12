#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }

    int count = 1;
    for (int i=1; i<n; i++) {
        bool res = true;
        for (int j=0; j<i; j++) {
            if (v[j] > v[i]) res = false;
        }
        if (res == true) count++;
    }

    cout << count << endl;
    return 0;
}
