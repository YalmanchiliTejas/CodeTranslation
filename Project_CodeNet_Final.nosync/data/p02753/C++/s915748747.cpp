#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(x) cout << x << endl;

int main() {
    string s;
    cin >> s;
    if(s == "AAA" || s == "BBB"){
        OP("No");
    }else{
        OP("Yes");
    }
}
