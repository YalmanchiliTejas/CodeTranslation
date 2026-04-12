#include <bits/stdc++.h>
using namespace std;
int a[1010];

int main() {
    while(true) {
        int n; cin >> n;
        if(n == 0) break;
        for(int i=0; i<n; ++i) cin >> a[i];
        sort(a, a + n);
        int sum = 0;
        for(int i=1; i+1<n; ++i) sum += a[i];
        cout << sum / (n - 2) << '\n';
    }
}
