#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define INF (1e9)

int N;

int main() {
    cin >> N;

    vi H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    int ans = 0;
    int hMax = H[0];
    for (int i = 0; i < N; i++) {
        if(hMax <= H[i]) ans++;
        hMax = max(hMax, H[i]);
    }

    cout << ans << endl;
    return 0;
}
