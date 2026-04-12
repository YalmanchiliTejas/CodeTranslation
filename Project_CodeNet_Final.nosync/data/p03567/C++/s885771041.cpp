#include <bits/stdc++.h>
using namespace std;
const int N = 10;
char str[N];

int main()
{
    cin>>str;
    int len = strlen(str);
    for(int i=0;i<len-1;i++) {
        if(str[i] == 'A' && str[i + 1] == 'C') {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
