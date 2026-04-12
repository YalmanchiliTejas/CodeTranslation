#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)

int main() {
    // your code goes here
    char c[5];
    cin >> c;
    if(c[0]!=c[1]||c[1]!=c[2]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}