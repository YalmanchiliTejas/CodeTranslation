#include<bits/stdc++.h>
using namespace std;

int N;

int main()
{
    char c;
    scanf(" %c",&c);
    scanf(" %c",&c);
    N = (c - '0') * 10;
    scanf(" %c",&c);
    N += (c - '0');
    if(N % 4)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
    }
    return 0;
}
