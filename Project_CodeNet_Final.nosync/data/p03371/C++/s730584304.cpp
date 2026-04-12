#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, Y;
    scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);
    int64_t ttl = 10000000000000000;
    for(int i=0; i<=2*max(X, Y); i+=2){
        int a=0, b=0, c;
        c=i;
        if(X-c/2>=0) a=X-c/2;
        if(Y-c/2>=0) b=Y-c/2;
        if (ttl > A*a+B*b+C*c)  ttl = A*a+B*b+C*c; 
    }
    cout << ttl << endl;
    return 0;
}

