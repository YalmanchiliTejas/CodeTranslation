#include <cstdio>

int main(){
    int r = 0;
    int g = 0;
    int b = 0;
    scanf("%d %d %d", &r, &g, &b);
    int n = 100*r + 10*g + b;
    if(n % 4 == 0){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}