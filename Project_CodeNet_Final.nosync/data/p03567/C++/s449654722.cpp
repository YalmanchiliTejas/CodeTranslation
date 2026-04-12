#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    for(int i=0; i<s.length()-1; i++) if(s[i] == 'A' && s[i+1] == 'C') return !printf("Yes");
    printf("No");
    return 0;
}