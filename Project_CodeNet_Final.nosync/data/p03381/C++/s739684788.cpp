#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int num;
    int idx;
}Data;
Data Num[200005];
int N, result[200005];

bool comp(Data t, Data u)
{
    return t.num < u.num;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &Num[i].num);
        Num[i].idx = i;
    }
    sort(Num, Num + N, comp);
    for(int i = 0; i < N; i++)
    {
        int temp;
        temp = Num[N / 2].num;
        if(i >= N / 2)
        {
            temp = Num[N / 2 - 1].num;
        }
        result[Num[i].idx] = temp;
    }
    for(int i = 0; i < N; i++)
    {
        printf("%d\n", result[i]);
    }
}