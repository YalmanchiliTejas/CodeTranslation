#include "cstdio"
#include "string.h"

int C[32];
int M[32];
int main()
{
    int n;
    char c;
    while (scanf("%d",&n) != EOF)
    {
        memset(C,0,sizeof(M));
        getchar();
        for (int i=0;i<n;i++)
        {
            memset(M,0,sizeof(C));
            while (c = getchar())
            {
                if (c == '\n')
                {
                    break;
                }
                M[int(c-'a')]++;
            }
            for (int k=0;k<26;k++)
            {
                if (i==0 || M[k]<C[k])
                {
                    C[k] = M[k];
                }
            }
        }
        for (int i=0;i<26;i++)
        {
             while (C[i]-->0)
             {
                 printf ("%c",char(i+'a'));
             }
        }
        putchar('\n');
    }
    return 0;
}
