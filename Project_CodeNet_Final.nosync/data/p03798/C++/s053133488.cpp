// luogu-judger-enable-o2
#include<bits/stdc++.h>
#define N 100009
using namespace std;
const int INF = 0x3f3f3f3f;
char s[N];
int ans[N];
int nx[4] = {1, 1, 0, 0};
int ny[4] = {1, 0, 0, 1};
bool check(int a, int b, int n)
{
    ans[0] = a; ans[1] = b;
    for(int i = 1; i < n - 1; i++)
    {
        if(s[i] == 'o')
        {
            if(ans[i]) ans[i + 1] = ans[i - 1];
            else ans[i + 1] = !ans[i - 1];
        }
        else
        {
            if(ans[i]) ans[i + 1] = !ans[i - 1];
            else ans[i + 1] = ans[i - 1];
        }
    }
    if(s[0] == 'o')
    {
        if(ans[0])
        {
            if(ans[1] != ans[n - 1]) return false;
        }
        else if(ans[1] == ans[n - 1]) return false;
    }
    else
    {
        if(ans[0])
        {
            if(ans[1] == ans[n - 1]) return false;
        }
        else if(ans[1] != ans[n - 1]) return false;
    }
    if(s[n - 1] == 'o')
    {
        if(ans[n - 1])
        {
            if(ans[0] != ans[n - 2]) return false;
        }
        else if(ans[0] == ans[n - 2]) return false;
    }
    else
    {
        if(ans[n - 1])
        {
            if(ans[0] == ans[n - 2]) return false;
        }
        else if(ans[0] != ans[n - 2]) return false;
    }
    return true;
}
int main()
{
    int n;
    scanf("%d %s", &n, s);
    for(int i = 0; i < 4; i++)
    {
        if(check(nx[i], ny[i], n))
        {
            for(int i = 0; i < n; i++)
            {
                if(ans[i]) printf("S");
                else printf("W");
            }
            printf("\n");
            exit(0);
        }
    }
    puts("-1");
    return 0;
}