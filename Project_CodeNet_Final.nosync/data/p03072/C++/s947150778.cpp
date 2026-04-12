#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    int mx = 0;
    int count = 0;
    for (int i=0; i<n; i++) {
        int curr;
        cin >> curr;
        if (curr >= mx) count++;
        mx = max(mx, curr);
    }
    cout << count;

}