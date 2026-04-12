#include <bits/stdc++.h>
using namespace std;
int main()
{
    string n, ans;
    cin >> n;
    ans = "Yes";
    if (n.at(0) == n.at(1) && n.at(1) == n.at(2))
        ans = "No";
    cout << ans << endl;
}