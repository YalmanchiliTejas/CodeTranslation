#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a,b,c; cin >> a >> b >> c;

    if((b*10+c)%4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;

}