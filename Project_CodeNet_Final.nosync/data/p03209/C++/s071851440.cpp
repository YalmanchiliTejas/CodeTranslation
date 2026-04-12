#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll height[51];
ll height2[51];
ll numpatties[51];
int N;
ll X;

ll count(int n, ll x) {
    int l = upper_bound(height2, height2 + n + 1, x - n) - height2 - 1;
    if (l < 0) return 0;
    ll ofs = x - height[l] - (n - l);
    if (ofs == 0) return numpatties[l];
    else if (ofs == 1) return numpatties[l] + 1;
    else return numpatties[l] + 1 + count(l, ofs - 1);
}

int main() {
    cin >> N >> X;
    height[0] = 1;
    numpatties[0] = 1; 
    for (int i = 1; i <= 50; i ++) {
        height[i] = height[i-1] * 2 + 3;
        numpatties[i] = numpatties[i-1] * 2 + 1;
    }
    for (int i = 0; i <= N; i ++) {
        height2[i] = height[i] - i;
    }
    cout << count(N, X) << endl;
}