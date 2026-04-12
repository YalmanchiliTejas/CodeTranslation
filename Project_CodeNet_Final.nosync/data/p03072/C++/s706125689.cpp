#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>

int main()
{
    int n;
    int count=1;
    int hoge=0;
    int H[100];
    std::cin >> n; 
    for(int i=0; i<n; i++){
    std::cin >> H[i];
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(H[i] < H[j]){
                goto a;
            }
        }
        count++;
        a:
        hoge++;
    }
    std::cout << count <<std::endl;
    return 0;
}