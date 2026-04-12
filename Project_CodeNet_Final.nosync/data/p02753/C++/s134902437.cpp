#include <bits/stdc++.h>
#define lli long long int
#define inf 2147483647
#define infll LLONG_MAX
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define Yes() cout << "Yes" << endl
#define No() cout << "No" << endl
#define YES() cout << "YES" << endl
#define NO() cout << "NO" << endl
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    string s;
    cin >> s;
    if(s[0] != s[1] || s[1] != s[2] || s[2] != s[0]) Yes();
    else No();
}