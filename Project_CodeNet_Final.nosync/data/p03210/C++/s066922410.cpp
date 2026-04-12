#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,(n))
typedef long long ll;
using namespace std;

int main() {
    int x; cin >> x;
    string ans = "NO";
    if (x == 3 || x == 5 || x == 7) ans = "YES";
    cout << ans << endl;
    return 0;
}