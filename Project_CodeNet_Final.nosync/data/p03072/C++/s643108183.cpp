#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

static const int MAX = 20;

int n, H[MAX], h = 0, s = 0;

int main() {
    scanf("%d", &n);

    for ( int i = 0; i < n; i++ ) {
        scanf("%d", &H[i]);
    }
    
    for ( int i = 0; i < n; i++ ) {
        if ( h <= H[i] ) {
            s++;
            h = H[i];
        }
    }

    printf("%d\n", s);
    return 0;
}
