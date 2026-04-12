#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

/*vector<int> p(n);
cin >> p[i]*/

int main(){

    string s;
    cin >> s;

    if(s[0] != s[1] || s[1] != s[2]) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}