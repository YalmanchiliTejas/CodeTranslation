#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int count = 0;
    int running_max = 0;
    for (int i = 0; i < n; ++i) {
        int h;
        cin >> h;
        if (running_max <= h) {
            ++count;
        }
        running_max = max(running_max, h);
    }
    cout << count << endl;
    return 0;
}