#include <stdio.h>


int main(){
    int r, g, b, num, rem;
    scanf("%d %d %d", &r, &g, &b);
    num = 100*r + 10*g + b;
    rem = num % 4;

    if(rem == 0){
	printf("YES");
    }else{
	printf("NO \n" );
    }    

    return 0;
}