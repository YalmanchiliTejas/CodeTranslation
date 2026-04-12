#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
    char S;
    int counterA = 0, counterB = 0;
    for(int i = 0 ; i < 3 ; i++)
    {
        scanf("%c", &S);
        if(S == 'A')
            counterA++;
        else
            counterB++;
    }

    if(counterA && counterB)
        printf("Yes\n");
    else
        printf("No");

    return 0;
}
