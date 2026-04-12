#include <bits/stdc++.h>
int main() {
    int n;
    scanf("%d", &n);
    int h[n];
    for (int i = 0; i < n; i++) { scanf("%d", &h[i]); }
    
    int max = h[0];
    int count = 1;
    for (int i = 1; i < n; i++) { 
        if (h[i] >= max) { 
            max = h[i];
            count++;
        }
    }
    printf("%d", count);
    return 0;
}