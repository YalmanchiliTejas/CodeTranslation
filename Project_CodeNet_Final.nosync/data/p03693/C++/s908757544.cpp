#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    a = a*100 + b*10 + c;
    cout << ( a%4 == 0 ? "YES" : "NO") << endl;
}
