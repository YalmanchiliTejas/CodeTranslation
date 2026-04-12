#include <stdio.h>

int main(void){
    int a, b, c, x, y;
    int total1, total2, total3;
    scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
    total1 = a * x + b * y;
    if(x > y){
        total2 = 2 * y * c + (x - y) * a;
        total3 = 2 * x * c;
    }
    else{
        total2 = 2 * x * c + (y - x) * b;
        total3 = 2 * y * c;
    }
    if(total1 < total2 && total1 < total3)
        printf("%d\n", total1);
    else{
        if(total2 < total3)
            printf("%d\n", total2);
        else
            printf("%d\n", total3);
    }
    return 0;
}
