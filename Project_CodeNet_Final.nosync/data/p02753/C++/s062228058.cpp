#include <bits/stdc++.h>

using namespace std;
#define  ll long long
#define ld long double
#define f first
#define s second

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    for(int i=1; i<s.size(); i++)
    {
        if (s[i] != s[i-1]) return cout << "Yes\n" , 0;
    }
    cout << "No\n";


    return 0;
}