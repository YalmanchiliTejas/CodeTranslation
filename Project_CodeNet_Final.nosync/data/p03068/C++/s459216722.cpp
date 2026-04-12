#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main(void)
{
    int n,k;
    string s;

    cin >> n;
    cin >> s;
    cin >> k;
    
    char c = s[k-1];
    string ans = "";

    for(int i = 0; i < n; i++)
    {
        if (s[i]==c) {
            ans += c;
        } else {
            ans += '*';
        }
    }
    
    cout << ans << endl;

    return 0;
}