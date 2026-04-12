#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
int main()
{
    string s;
    cin >> s;
    int cnt = 0;
    if (s[0] != s[1]) cnt++;
    if (s[1] != s[2]) cnt++;
    if (cnt == 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}