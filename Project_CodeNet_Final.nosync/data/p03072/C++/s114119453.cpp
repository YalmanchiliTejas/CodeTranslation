#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int N;
    scanf("%d", &N);
    int H[N];
    for(int i = 0;i < N;i++) {
        scanf("%d", &H[i]);
    }
    int max_h = -334;
    int count = 0;
    for(int i = 0;i < N;i++) {
        if(max_h <= H[i]) {
            max_h = H[i];
            count++;
        }
    }
    printf("%d\n", count);
}
