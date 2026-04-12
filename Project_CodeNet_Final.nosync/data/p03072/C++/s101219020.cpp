#include <cstdio>
#include <iostream>
using namespace std;
int N, arr[25], Max, result;

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        if(Max <= arr[i])
        {
            Max = arr[i];
            result++;
        }
    }
    printf("%d", result);
}