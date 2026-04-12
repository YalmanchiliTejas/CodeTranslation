#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, G, B;
    scanf("%d%d%d", &R, &G, &B);
    int number = R*100 + G*10 + B;
    if(number % 4 == 0) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}
