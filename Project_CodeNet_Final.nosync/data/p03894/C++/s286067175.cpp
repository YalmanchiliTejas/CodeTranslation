#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
bool before[100500];
bool after[100500];

int main() {
    //cout.precision(10);
    int N, Q;
    cin >> N >> Q;
    before[1] = true;
    after[2] = true;
    while(Q--) {
        int a, b;
        cin >> a >> b;
        swap(before[a], before[b]);
        swap(after[a], after[b]);
        /*
        before[a] |= before[b];
        before[b] |= before[a];
        after[a] |= after[b];
        after[b] |= after[a];
        */
        after[a+1] |= (before[b] || before[a]);
        after[a-1] |= (before[b] || before[a]);
        after[b-1] |= (before[a] || before[b]);
        after[b+1] |= (before[a] || before[b]);
        after[a] |= (before[a-1] || before[a+1]);
        after[b] |= (before[b-1] || before[b+1]);
    }
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        if(after[i] || before[i]) {
            cerr << i << endl;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
