#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) (v).begin(),(v).end()
#define out(a) cout << (a) << endl
using namespace std;
using ll = long long;
int main(){
    int x, y, z;
    cin >> x >> y >> z;
    int ans = (x - z) / (y + z);
    out(ans);
}