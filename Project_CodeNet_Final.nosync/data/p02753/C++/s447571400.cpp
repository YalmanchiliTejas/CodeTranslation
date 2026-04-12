#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,i0,n) for(int i=i0;i<n;++i)

int main()
{
    string s;
    cin >> s;
    if(s[0] == s[1] && s[0] == s[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}