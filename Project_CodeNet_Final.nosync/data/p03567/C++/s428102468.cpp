#include<bits/stdc++.h>
using namespace std;

char S[100010] = {0};

int main()
{
    scanf("%s",S);

    int N = strlen(S);

    for(int i = 0; i < N - 1; i++)
    {
        if(S[i] == 'A' && S[i + 1] == 'C')
        {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
