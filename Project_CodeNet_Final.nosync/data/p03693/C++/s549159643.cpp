#include <bits/stdc++.h>
using namespace std;
typedef long int li;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c; cin >> a >> b >> c;

    if ((a*100 + b*10 + c)%4==0) cout << "YES";
    else cout << "NO";

    cout << "\n";    

    return 0;
}