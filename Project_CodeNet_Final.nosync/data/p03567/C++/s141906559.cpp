#include "bits/stdc++.h"
using namespace std;
int main()
{
    char a[5];
    scanf("%s", a);
    for (int i = 0; i < 4; i++)
    {
        if (a[i] == 'A' && a[i + 1] == 'C')
        {
            printf("Yes\n");
            break;
        }
        if (i == 3)
        {
            printf("No\n");
        }
    }
}
