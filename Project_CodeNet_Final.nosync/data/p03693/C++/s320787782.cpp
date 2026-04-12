#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t,n,a,b,c;
    t = 1;
    while(t--) {
     cin >> a >> b >> c;
     n = a * 100 + b * 10 + c;
     if(n % 4 == 0)
      cout << "YES" << endl;
     else
      cout << "NO" << endl;
    }
    return 0;
}
