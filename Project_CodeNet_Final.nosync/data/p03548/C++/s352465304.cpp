#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(void){
    int x = 0, y = 0, z = 0; 
    int ans = 0;

    scanf("%d%d%d", &x, &y, &z);    

    printf("%d\n", (x - z) / (y + z));
    return 0;

} 
