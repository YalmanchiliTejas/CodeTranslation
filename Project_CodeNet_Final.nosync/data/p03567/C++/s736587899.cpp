#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    char s[11];
    while (~scanf("%s",s)){
        if (strstr(s,"AC") != 0)  puts("Yes");
        else  puts("No");
    }
    return 0;
}
