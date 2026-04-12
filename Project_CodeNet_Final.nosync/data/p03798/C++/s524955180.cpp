#include <cstdio>
#include <algorithm>
#include <cstring>

#define NMAX (100000 + 7)

using namespace std;
int n, v[NMAX];
char s[NMAX];
bool p;

void init()
{
    for(int i = 1; i<= n; ++i) v[i] = 0;
}
bool build()
{
    for(int i = 3; i<= n; ++i)
    {
        if(s[i-1] == 'o' && v[i-1] == 1)
        {
            v[i] = v[i-2];
            continue;
        }
        if(s[i-1] == 'o' && v[i-1] == 2)
        {
            v[i] = 3 - v[i-2];
            continue;
        }
        if(s[i-1] == 'x' && v[i-1] == 1)
        {
            v[i] = 3 - v[i-2];
            continue;
        }
        v[i] = v[i-2];
    }
    for(int i = 2; i<= n-1; ++i)
    {
        if(s[i] == 'o' && v[i] == 1 && v[i-1] != v[i+1]) return 0;
        if(s[i] == 'o' && v[i] == 2 && v[i-1] == v[i+1]) return 0;
        if(s[i] == 'x' && v[i] == 1 && v[i-1] == v[i+1]) return 0;
        if(s[i] == 'x' && v[i] == 2 && v[i-1] != v[i+1]) return 0;
    }
    if(s[1] == 'o' && v[1] == 1 && v[2] != v[n]) return 0;
    if(s[1] == 'o' && v[1] == 2 && v[2] == v[n]) return 0;
    if(s[1] == 'x' && v[1] == 1 && v[2] == v[n]) return 0;
    if(s[1] == 'x' && v[1] == 2 && v[2] != v[n]) return 0;
    if(s[n] == 'o' && v[n] == 1 && v[1] != v[n-1]) return 0;
    if(s[n] == 'o' && v[n] == 2 && v[1] == v[n-1]) return 0;
    if(s[n] == 'x' && v[n] == 1 && v[1] == v[n-1]) return 0;
    if(s[n] == 'x' && v[n] == 2 && v[1] != v[n-1]) return 0;
    return 1;
}
void afisare()
{
    for(int i = 1; i<= n; ++i)
    {
        if(v[i] == 1) printf("S");
        if(v[i] == 2) printf("W");
    }
    printf("\n");
}

int main()
{
    scanf("%d", &n);
    scanf("%s", s+1);
    init();
    v[1] = 1;
    v[2] = 1;
    p = build();
    if(p == 1)
    {
        afisare();
        return 0;
    }
    init();
    v[1] = 1;
    v[2] = 2;
    p = build();
    if(p == 1)
    {
        afisare();
        return 0;
    }
    init();
    v[1] = 2;
    v[2] = 1;
    p = build();
    if(p == 1)
    {
        afisare();
        return 0;
    }
    init();
    v[1] = 2;
    v[2] = 2;
    p = build();
    if(p == 1)
    {
        afisare();
        return 0;
    }
    printf("-1\n");
    return 0;
}