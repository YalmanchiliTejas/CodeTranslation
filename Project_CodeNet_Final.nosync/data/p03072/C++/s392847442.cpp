#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

// bool compPair(const pair<int, int>& arg1, const pair<int, int>& arg2) {
//     return arg1.first > arg2.first;
// }

int main(void) {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a.at(i);
    }

    int hmax = a.at(0), ans=1;

    for(int i=1;i<n;i++) {
        if(hmax<=a.at(i)) {
            ans++;
            hmax = a.at(i);
        }
    }

    cout << ans << endl;
    return 0;
}
