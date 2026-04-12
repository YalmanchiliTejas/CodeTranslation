#include <bits/stdc++.h>
using namespace std;

int a[100], i;
string s;

int main() {
    for(cin >> s; i < 3; i++)
        a[s[i]]++;

    if(a['A'] && a['B'])
        cout << "Yes";
    else
        cout << "No";
}
