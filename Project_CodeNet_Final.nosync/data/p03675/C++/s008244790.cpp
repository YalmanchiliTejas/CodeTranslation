#include <bits/stdc++.h>

using namespace std;

int b[200001];

int main(void) {
    int i, a, n;
    cin >> n;
    int mid = (n - 1) / 2;
    for(i=0; i<n; i++) {
        cin >> a;
        if(i % 2 == 0) b[mid-(i+1)/2] = a;
        else           b[mid+(i+1)/2] = a;
    }

    if(n % 2 == 0) for(i=n-1; i>=0; i--) {
        printf("%d ", b[i]);
    }
    else for(i=0; i<n; i++) {
        printf("%d ", b[i]);
    }

    puts("");

    return 0;
}