#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

const int CMax = 100002;

int n, A[CMax], ats;
string S;

int main() {
    cin >> S;

    for (int i = 0; i < S.length()-1; i++) {
        if (S[i] == 'A' && S[i+1] == 'C') {
            printf("Yes\n");
            return 0;
        }
    }

    printf("No\n");
}
