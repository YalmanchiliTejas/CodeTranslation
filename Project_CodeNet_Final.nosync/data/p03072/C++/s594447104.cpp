#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#include <typeinfo>
#include <string>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<ll> VL;

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int H[N];
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    int ans = 0;
    int h = 0;
    for (int i = 0; i < N; ++i) {
        if (H[i] >= h) {
            ans++;
            h = max(h, H[i]);
        }
    }

    cout << ans << endl;
}