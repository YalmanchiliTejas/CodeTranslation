#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <string>
#define REP(i,n) for(int i=0;i<n;i++)
using Int = long long;
using namespace std;
int main()
{
    int N; cin >> N;
    vector<bool> same(N);
    REP(i, N) {
        char c; cin >> c;
        same[i] = (c == 'o');
    }
    vector<bool> sheep(N);
    REP(i, 4) {
        sheep[0] = ~i & 1;
        sheep[1] = ~i & 2;
        for (int j = 2; j < N; j++) {
            sheep[j] = sheep[j-2] ^ ~same[j-1] ^ ~sheep[j-1];
        }
        if ((sheep[0] == (sheep[N-2] ^ ~same[N-1] ^ ~sheep[N-1])) &&
            (sheep[1] == (sheep[N-1] ^ ~same[0] ^ ~sheep[0]))) {
            REP(i, N) cout << "WS"[sheep[i]];
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}