#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;


int main() {

    int a, b, c;
    cin >> a >> b >> c;
    if ((100*a+10*b+c) % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}