#include <bits/stdc++.h>
using namespace std;

using ll = long long; 

const int mod = 1e9+7;

int add(int a, int b) {
    int c = a + b;
    if (c >= mod) {
        c -= mod;
    }
    return c;
}


int main() {
    int a;
    int b;
    
    scanf("%d%d", &a, &b);
    
    if (b >= a) {
        printf("Yes");
    }
    else {
        printf("No");
    }
	
	return 0;
}