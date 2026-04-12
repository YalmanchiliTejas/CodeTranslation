#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main()
{
    char s[3];
    scanf("%c", &s[0]);
    scanf("%c", &s[1]);
    scanf("%c", &s[2]);

    puts(s[0] == s[1] && s[1] == s[2] ? "No" : "Yes");
}