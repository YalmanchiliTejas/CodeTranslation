#include<bits/stdc++.h>

using namespace std;
using ll = long long;



int main()
{
    int n,k;
    string s;
    cin >> n >> s >> k;
    char t = (s[k - 1]);
    for(auto &i : s)i = (i == t ? t : '*');
    cout << s << endl;
}