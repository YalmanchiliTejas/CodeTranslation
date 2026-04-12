#include <bits/stdc++.h>

using namespace std;

int n;
bool flag = true;
int cnt = 0;

int main () {
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=i; j>=0; j--) {
            if (a[i] < a[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cnt++;
        }
        flag = true;
    }
    cout << cnt << endl;

    return 0;
}