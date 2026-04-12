#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

#define Nmax 3003
#define modulo 998244353

int N, S;
int A[Nmax], cnt[Nmax][Nmax];

int main() {
    cin >> N >> S;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    
    int total = 0;
    for (int i = 1; i <= N; ++i) {
        cnt[i-1][0] = i;
        for (int j = 1; j < A[i]; ++j)
            cnt[i][j] = cnt[i-1][j];
        for (int j = A[i]; j <= S; ++j) {
            cnt[i][j] = ((long long)cnt[i-1][j] + cnt[i-1][j - A[i]]) % modulo;
        }
        total += cnt[i][S];
        total %= modulo;
    }
    
    cout << total;
    
    return 0;
}

