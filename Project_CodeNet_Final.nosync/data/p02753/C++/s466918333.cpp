#include <cstdio>



int main(){
    char A,B,C;

    A=getchar();
    B=getchar();
    C=getchar();

    if (A==B&&B==C)
        puts("No");
    else
        puts("Yes");

    return 0;
}