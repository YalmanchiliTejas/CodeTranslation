#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long x;
    scanf("%ld", &x);
    if(x >= 30){
        printf("Yes");
    }
    else {
        printf("No");
    }
    
    return 0;
}
