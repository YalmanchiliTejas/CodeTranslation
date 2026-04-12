#include "bits/stdc++.h"

using namespace std;

int main() {
    int a;
    scanf("%d", &a);
    vector <int> n(a);
    for(int i = 0; i < a; i++) scanf("%d", &n[i]);
    int maxi = n[0], cnt = 1;
    for(int i = 1; i < a; i++) {
        if(n[i] >= maxi) {
            cnt++;
            maxi = n[i];
        }
    }
    printf("%d\n", cnt);

}