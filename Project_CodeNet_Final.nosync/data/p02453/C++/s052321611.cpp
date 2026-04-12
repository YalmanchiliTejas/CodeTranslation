#include<algorithm>
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int &i : a) cin >> i;
    int T;
    cin >> T;
    while (T--) {
        int t;
        cin >> t;
        cout << (lower_bound(a, a + n, t) - a) << endl;
    }
    return 0;
}
