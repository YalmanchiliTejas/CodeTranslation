#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
#define INF 999999999
typedef long long ll;
using namespace std;
int main() {
    int N;
    cin >> N;
    int H[N];
    REP(i, N) cin >> H[i];
    int ocean = 0;
    int high = 0;
    REP(i, N) {
        if(high <= H[i]) {
            high = H[i];
            ocean++;
        }
    }
    cout << ocean << "\n";
}