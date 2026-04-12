#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main() {
    int n; cin >> n;
    int h[20];
    for (int i=0; i<n; i++) {
        cin >> h[i];
    }
    int res = 0;
    for (int i=0; i < n; i++) {
        bool flag = true;
        for (int j=0; j <= i; j++) {
            if (h[i] >= h[j]) continue;
            else {
                flag = false;
                break;
            }
        }
        if(flag == true) res++;
    }

    cout << res << "\n";
}