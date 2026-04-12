#include<stdio.h>

int main()
{
    int n, h[20], view = 1;
    bool flag;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &h[i]);
    for(int i = 1; i < n; i++)
    {
        flag = true;
        for(int j = 0; j < i; j++)
        {
            if((h[i] - h[j]) < 0) flag = false;
        }
        if(flag) view++;
    }
    printf("%d", view);
    return 0;
}