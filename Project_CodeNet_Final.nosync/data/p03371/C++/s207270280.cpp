#include <cstdio>


int max(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int main(){
    int i;
    int A, B, C, X, Y;
    scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);

    int tmp;
    int min = A * X + B * Y;
    for(i=0; i<100000+1; i++){
        tmp = i * 2 * C + max(0, X - i) * A + max(0, Y - i) * B;
        if(min > tmp)
            min = tmp;
    }
    
    printf("%d\n", min);

    return 0;
}
