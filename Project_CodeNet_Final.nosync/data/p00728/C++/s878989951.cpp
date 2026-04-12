#include <iostream>
#include <cstdio>
using namespace std;
 
int main() {
    int n, data;
    while(1) {
        scanf("%d", &n);
        if (n == 0) break;
        int sum=0, max=0, min=1001;
        for (int i=0; i<n; i++) {
            scanf("%d", &data);
            sum+=data;
            if (max < data) max=data;
            if (data < min) min=data;
        }
        printf("%d\n", (sum-max-min)/(n-2));
    }
}