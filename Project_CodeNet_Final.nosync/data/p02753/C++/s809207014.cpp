#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    char ch1,ch2,ch3;
    ch1=getchar();ch2=getchar();ch3=getchar();
    if (ch1==ch2 & ch2==ch3){
        printf("No");
    }else
    printf("Yes");

}
