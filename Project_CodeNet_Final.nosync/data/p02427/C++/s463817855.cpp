#include <bits/stdc++.h>

using namespace std;


int main(){
    unsigned long n;
    scanf("%lu",&n);

    bitset<18> subset_flag(0);
    for(unsigned long i = 0;i < pow(2,n);i++){
        subset_flag = bitset<18>(i);
        printf("%lu:",i);
        for(unsigned long j = 0;j < n;j++){
            if(subset_flag.test(j)) printf(" %lu",j);
        }
        printf("\n");
    }

    return 0;   
}

