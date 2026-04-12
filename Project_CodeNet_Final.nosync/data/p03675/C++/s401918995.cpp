#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

const int N = 222222;
int n;
int a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if(n & 1) {
        for(int i = n; i >= 1; i -= 2) {
            cout << a[i] << " ";
        }
        for(int i = 2; i <= n - 1; i += 2) {
            cout << a[i] << " ";
        }
        cout << endl;
    } else {
        for(int i = n; i >= 2; i -= 2) {
            cout << a[i] << " ";
        }
        for(int i = 1; i <= n - 1; i += 2) {
            cout << a[i] << " " ;
        }
        cout << endl;
    }
    return 0;
}