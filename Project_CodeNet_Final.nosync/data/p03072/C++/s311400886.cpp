#include <stdio.h>

int main(void)
{
    int mountains;
    int seeableinn = 0;
    int highest = 0;

    scanf("%d", &mountains);
    int height[mountains];

    for(int i = 0; i < mountains; i++)
        scanf("%d", &height[i]);

    for(int i = 0; i < mountains; i++)
        if(highest <= height[i])
        {
            seeableinn++;
            highest = height[i];
        }
    printf("%d\n", seeableinn);

    return 0;
}