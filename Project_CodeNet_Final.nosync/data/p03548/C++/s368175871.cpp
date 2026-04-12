#include<bits/stdc++.h>
using namespace std;

int X, Y, Z;

int main(){
    scanf("%d%d%d", &X, &Y, &Z);
    int cnt = 0;
    int total = Y +Z;
    while(total + Z <= X) {
        total += Y + Z;
        cnt++;
    }
    printf("%d", cnt);
    return 0;
}
