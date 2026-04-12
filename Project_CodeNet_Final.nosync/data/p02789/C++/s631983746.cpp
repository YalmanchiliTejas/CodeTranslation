#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repr(i, a, b) for (int i=a; i<(b); ++i)
#define reprev(i, n) for (int i=n-1; i>=0; --i)
#define reprrev(i, a, b) for (int i=b-1; i>=(a); --i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    cout << fixed << setprecision(10);
    
    int N, M; cin >> N >> M;
    if (N==M) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}