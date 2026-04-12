#include<bits/stdc++.h>
using namespace std;
vector<int> primes;
int A[1005];

void f(int a) {
    for(int i = 2; i * i <= a; i++) {
        if(a % i != 0) continue;
        primes.push_back(i);
        while(a % i == 0) a /= i;
    }
    if(a != 1) primes.push_back(a);
}

int main() {
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        f(A[i]);
    }
    long long ans = 0;
    for(auto val : primes) {
        long long  now = 0;
        for(int i = 1; i <= N; i++) {
            if(A[i] % val == 0) now += A[i];
        }
        ans = max(ans, now);
    }
    cout << ans << endl;
}
