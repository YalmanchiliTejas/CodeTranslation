#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    #define N 200'000
    static int x[N];
    static int a[N];
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        a[i] = x[i];
    }
    sort(x, x + n);
    int Lm = x[(n-1) / 2];
    int Rm = x[n / 2];
    for(int i = 0; i < n; i++) {
        if(a[i] <= Lm) {
            cout << Rm << endl;
        } else {
            cout << Lm << endl;
        }
    }
    return 0;
}
