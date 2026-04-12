#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long int X;
vector<long long int> a(51), p(51); //各レベルに対する層の数a, パティの数p

long long int patti(int N, long long int X) {
    if (X < 0 || N < 0) {
        return 0;
    } else if (X > a[N] / 2) {
        return p[N] - patti(N - 1, a[N] - X - 1);
    } else {
        return patti(N - 1, X - 1);
    }
}

int main() {
    cin >> N >> X;
    
    a[0] = 1; p[0] = 1;
    for (int i = 0; i < N; i++) {
        a[i + 1] = 2 * a[i] + 3;
        p[i + 1] = 2 * p[i] + 1;
    }
    
    cout << patti(N, X) << endl;
}