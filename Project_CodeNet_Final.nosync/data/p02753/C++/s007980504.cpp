#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    cin >> s;
    if (s.find('A') != string::npos &&
        s.find('B') != string::npos)
        printf("Yes\n");
    else printf("No\n");
    return 0;
}
