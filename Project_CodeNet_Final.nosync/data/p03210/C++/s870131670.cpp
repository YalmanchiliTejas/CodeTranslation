#include <stdio.h>
#include <math.h>
//#include <algorithm>

int main(int argc, char* argv[])
{
    long n;
    scanf("%ld", &n);

    if(n==3 || n==5 || n==7) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }

    return 0;
}

