#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    int left = b[n/2-1], right = b[n/2];
    if (left == right) {
        for (int i = 0; i < n; i++)
            cout << left << endl;
    } else {
        for (int i = 0; i < n; i++) {
            if (a[i] <= left)
                cout << right << endl;
            else
                cout << left << endl;
        }
    }

}