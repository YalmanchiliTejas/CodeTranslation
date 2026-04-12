#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;

const int N = 100010;

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < 1 << n; i ++)
    {
        printf("%d:", i);
        for(int j = 0; j < n; j ++)
            if(i >> j & 1)  printf(" %d", j);
        puts("");
    }
    return 0;
}
