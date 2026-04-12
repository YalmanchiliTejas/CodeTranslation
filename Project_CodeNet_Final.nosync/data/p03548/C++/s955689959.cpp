#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;



int main() {
    int x,y,z;
    cin >> x >>y >>z;
    int ans = (x-z)/(y+z);
    cout << ans << endl;
}
