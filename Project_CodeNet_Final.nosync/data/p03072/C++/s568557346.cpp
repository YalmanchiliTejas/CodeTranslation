#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int h[100];
    int count = 0;
    int maxh = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for(int i = 0; i < n; i++) {
        if (maxh <= h[i]) {
            count++;
            maxh = h[i];
        }
    }
    cout << count << endl;
}