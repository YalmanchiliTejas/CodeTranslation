#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdint>
#include <limits>
#include <bits/stdc++.h>
#include<string>
using namespace std;
int main(void)
{
    
    uint64_t n;
    int k,ans;
    char s[334];
    cin >> s;
    if((s[0]=='A' &&  s[1]=='A' && s[2]=='A') || (s[0]=='B' &&  s[2]=='B' && s[1]=='B'))
    {
    cout << "No" << endl;
    }
    else cout << "Yes" << endl;
}
