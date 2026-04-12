#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int ans = N * 800;
    ans -= (N / 15) * 200;

    cout << ans << endl;
}