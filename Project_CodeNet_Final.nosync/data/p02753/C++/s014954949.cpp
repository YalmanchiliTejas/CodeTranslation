#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n)  for(int i=0;i<n;i++)
#define per(i,n)  for(int i=n-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    bool flag1 = false, flag2 = false;
    rep(i,3){
        if (s[i] == 'A') flag1 = true;
        if (s[i] == 'B') flag2 = true;
    }
    if (flag1 && flag2) cout << "Yes";
    else cout << "No";
    
    return 0;
}
