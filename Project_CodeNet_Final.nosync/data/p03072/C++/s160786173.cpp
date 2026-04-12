#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define loop(i, a, b) for (int i = a; i < (int)(b); i++)
 
 
int main() {
    int N;
    cin >> N;
    int h[N];
    rep(i, N) cin >> h[i];
    int count = 1;
    int hMax = h[0];
    loop(i, 1, N) {
        if (h[i] >= hMax) {
            hMax = h[i];
            count += 1;
        }
    }
    cout << count << endl;
    return 0;
}