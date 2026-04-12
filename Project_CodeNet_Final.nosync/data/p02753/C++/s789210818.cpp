#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;   cin >> s;

    bool Ok = (s[0] == s[1] && s[1] == s[2]);

    puts(Ok ? "No" : "Yes");
}
