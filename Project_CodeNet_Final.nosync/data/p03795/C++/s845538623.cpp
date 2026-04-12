#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)==1){
        int meal=n*800-(n/15)*200;
        printf("%d\n",meal);
    }
    return 0;
}
