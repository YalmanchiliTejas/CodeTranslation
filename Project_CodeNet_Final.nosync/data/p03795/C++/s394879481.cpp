#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;

int N;

int main() {
    cin >> N; 
    int cost = 800 * N;
    int back = (N / 15) * 200;

    printf("%d\n", cost - back);
}