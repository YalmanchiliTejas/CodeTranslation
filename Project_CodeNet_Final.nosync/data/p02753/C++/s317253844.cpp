#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    string s,ans="Yes";
    cin >> s;
    if(s[0]==s[1]&&s[1]==s[2]) ans ="No";
    cout << ans << endl;
}
