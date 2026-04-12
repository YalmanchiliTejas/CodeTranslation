#include <bits/stdc++.h>
using namespace std;

int main() {
    long n;
    cin >> n;
    deque<long long> b;
    for (long i=0; i<n; i++) {
        long long a;
        cin >> a;
        if (i%2 == 0)
            b.push_back(a);
        else
            b.push_front(a);
    }
    if (n%2)
        reverse(b.begin(), b.end());
    for (long long bi: b)
        printf("%lld ", bi);
    puts("");
    return 0;
}