#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    int a = 0;
    string s;
    cin >> s;
    for (int i = 1; i<3 ; i++)
    {
        if (s[i]!= s[i-1]) { cout << "Yes"; a = 1; break;}
    }
    if (a== 0 ) cout << "No";
}
