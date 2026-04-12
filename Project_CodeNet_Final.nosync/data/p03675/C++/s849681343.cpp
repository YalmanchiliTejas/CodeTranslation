#include<bits/stdc++.h>
using namespace std;

const int MAX = 200005;
int A[MAX];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);

    for (int i = n - 1; i >= 0; i -= 2) printf("%d\n", A[i]);
    int x;
    if (n % 2 == 0) x = 0;
    else x = 1;
    for (int i = x; i < n; i += 2) printf("%d\n", A[i]);
    
    return 0;
}