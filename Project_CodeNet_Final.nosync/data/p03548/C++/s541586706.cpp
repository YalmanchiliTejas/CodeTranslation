#include <cstdio>

using namespace std;
int main()
{
    int X,Y,Z;
    int num;

    //input : X Y Z
    scanf("%d %d %d", &X, &Y, &Z);

    num = (X-Z)/(Y+Z);
    printf("%d",num);

    return 0;
}