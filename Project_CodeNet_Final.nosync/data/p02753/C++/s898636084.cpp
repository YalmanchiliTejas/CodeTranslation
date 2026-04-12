#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
const int MOD=1e9+7;
 
int main() {
    string s;
    cin >> s;
    if (s[0]==s[1] && s[1]==s[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
}