#include <iostream>
#include <algorithm>

std::string N;

int Kt[4][101];

int K(int k, int n) {
    // n-k zeros
    if (k > n) return 0;
    if (k==0) return 1;
    return 9*Kt[k-1][n-1] + Kt[k][n-1];//9*K(k-1, n-1) + K(k, n-1);
}

int f(int k, int n) {
    if (k==0) return 1;
    if (n >= N.length()) return 0;
    if (N[n] == '0') return f(k, n+1);
    return (N[n]-'1')*K(k-1, N.length()-n-1) + K(k, N.length()-n-1) + f(k-1, n+1);
}

int main() {
    std::ios_base::sync_with_stdio(0);
    int k;
    std::cin >> N >> k;
    for (int kk=0;kk<=3;++kk)
        for (int n=0;n<=100;++n)
            Kt[kk][n] = K(kk,n);
    std::cout << f(k, 0);
    return 0;
}