#include <bits/stdc++.h>

#define FILE
#define fr first
#define se second

using namespace std;

const long long N = 2e5 + 7;
const long long inf = 1e9 + 7;
const long long mod = 1e9 + 7;

int main()
{
    #ifdef FILEs
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    if(s[0] != s[1] || s[1] != s[2]){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
}
