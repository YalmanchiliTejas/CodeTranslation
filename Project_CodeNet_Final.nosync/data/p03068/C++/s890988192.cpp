#include <iostream>

using namespace std;

int main()
{
    char s[11];
    int N,K;
    char flag;
    int i;
    scanf("%d", &N);
    fflush(stdin);
    scanf("%s", s);
    fflush(stdin);
    scanf("%d", &K);
    flag = s[K - 1];
    for(i = 0; i < N; i++)
    {
        if(s[i] != flag)
        {
            s[i] = '*';
        }
    }
    printf("%s\n", s);
    return 0;
}
