#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ll long long

int main() {

    //入力
    int x;
    string ans;

    cin >> x;
    if (x >= 30)
        ans = "Yes";
    else
        ans = "No";

    cout << ans << endl;

    return 0;
}
