/// hi_im_manh :D
#include <bits/stdc++.h>
#define reset(a,n) memset(a,0,(n+1)*sizeof(int))
#define endl "\n"
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define intmax INT_MAX
#define intmin INT_MIN
#define ll long long
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

#define duckman "TASK"

#define input freopen(duckman".inp", "r", stdin);
#define output freopen(duckman".out", "w", stdout);

#define nmax 22000
using namespace std;


int main()
{
    fast;
//    input;
//    output;

    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (s[0] == s[2]) {
        cout << "No";
    }
    else {
        cout << "Yes";
    }
    return 0;
}
/*

*/
