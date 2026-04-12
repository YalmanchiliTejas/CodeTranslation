#include <bits/stdc++.h>
using namespace std;
int N;
long long X;
vector<long long> L(52, -1);
vector<long long> P(52, -1);
long long length(int n){
    if (n == 0) return 1;
    if (L[n] != -1) return L[n];
    L[n] = 3 + 2 * length(n-1);
    return L[n];
};

long long pat(int n){
    if (n == 0) return 1;
    if (P[n] != -1) return P[n];
    P[n] = 1 + 2 * pat(n-1);
    return P[n];
};

long long count(int n, long long x){
    if (x == 1LL){
      	if (n == 0) return 1;
        return 0LL;
    }
    if (x <= length(n-1) + 1){
        return count(n-1, x-1);
    }
    else if (length(n-1)+2 == x){
        return pat(n-1) + 1;
    }
    else if (2 * length(n-1) + 2 >= x){
        return pat(n-1) + 1 + count(n-1, x - length(n-1) - 2);
    }
    return 2 * pat(n-1) + 1;
}
int main() {
    cin >> N >> X;
    cout << count(N, X) << endl;
}


