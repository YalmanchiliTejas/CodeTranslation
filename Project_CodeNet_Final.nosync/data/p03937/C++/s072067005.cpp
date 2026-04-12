#include <bits/stdc++.h>

using namespace std;

int N, M;

int main()
{
    scanf("%d%d", &N, &M);
    int y=0;
    for(int i=0; i<N; i++)
    {
        string s;
        cin>>s;
        for(int j=0; j<M; j++) if(s[j]=='#')
        {
            if(j>=y)
                y=j;
            else
                return printf("Impossible\n"), 0;
        }
    }
    printf("Possible\n");
    return 0;
}
