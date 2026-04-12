#include <bits/stdc++.h>
#define mod 1000000007
#define db(a) cout << a << endl
#define db2(a,b) cout << a << " " << b << endl
#define dbp(a) cout << a.first << " " << a.second << endl
#define adb(a) for(auto i:a) cout << i << " "; cout << endl
#define adb2(a) for(auto i:a) cout << i.first << " " << i.second << endl;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define N 100010
using namespace std;

int main()
{
    fastIO;
    string s;
    cin >> s;

    if(s == "AAA" || s == "BBB") cout << "No" << endl;
    else cout << "Yes" << endl;
}