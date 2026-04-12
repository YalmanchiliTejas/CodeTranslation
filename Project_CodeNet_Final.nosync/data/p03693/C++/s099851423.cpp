//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <numeric>
typedef long long Int;
#define rep(i,a,b) for(Int i=a;i<b;++i)
#define rrep(i,a,b) for(Int i=a;i>=b;--i)
using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int r, g, b; cin >> r >> g >> b;
    if ((r*100+g*10+b)%4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}
