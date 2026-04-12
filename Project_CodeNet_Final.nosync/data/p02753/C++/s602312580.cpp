#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    if (s[1] == s[0] && s[1] == s[2])
        cout << "No";
    else
        cout << "Yes";

    return 0;
}
