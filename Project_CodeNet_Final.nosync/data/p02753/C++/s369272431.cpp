#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

int main()
{
    string s;
    cin >> s;

    if((s[0] == s[2] || s[0] == s[1] || s[1] == s[2]) && !(s[0] == s[1] && s[1] == s[2]))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
