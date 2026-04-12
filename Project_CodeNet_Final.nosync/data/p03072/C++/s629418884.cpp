#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, Count = 0, Max = 0;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (Max <= x)
            Count++, Max = x;
    }
    cout << Count << endl;
}
