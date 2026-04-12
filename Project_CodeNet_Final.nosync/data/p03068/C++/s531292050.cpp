#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const static int MAX = 10;

int n, k;
char S[MAX], r;
string s;

int main() {
    scanf("%d", &n);
    scanf("%s", S);
    s = S;
    scanf("%d", &k);
    r = s[k-1];

    for ( int i = 0; i < n; i++ ) {
        if ( s[i] != r ) {
            s[i] = '*';
        }
    }
    
    printf("%s\n", s.c_str());
    return 0;
}

