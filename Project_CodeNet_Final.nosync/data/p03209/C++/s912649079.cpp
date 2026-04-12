#include<iostream>
#include<vector>
using namespace std;

vector<long long> a(51), p(51);

long long patty(long long l, long long x) {
    if (x == 0) return 0;
    if (l == 0) return 1;
    if (x >= 2 * a[l - 1] + 2) return p[l];
    else if (x >= a[l-1] + 2) {
        return p[l - 1] + 1 + patty(l - 1, x - (a[l - 1] + 2));
    }
    else return patty(l-1,x-1);
        
}

int main() {
    long long n, x; cin >> n >> x;
    a[0] = p[0] = 1;
    for (long long i = 0; i < 50; i++) {
        a[i + 1] = 2 * a[i] + 3;
        p[i + 1] = 2 * p[i] + 1;
    }
    cout << patty(n, x) << endl;

    return 0;
}
