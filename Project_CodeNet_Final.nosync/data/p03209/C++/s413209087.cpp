#include <bits/stdc++.h>
using namespace std;

int n;
long long int x;

long long int f(int lv, long long int x) {
    if (lv == 0) return 1;

    long long int mid = 4*pow(2, lv-1)-1;

    if (x == 1) return 0;
    if (x < mid)  return f(lv-1, x-1);
    if (x == mid) return (2*pow(2, lv-1)-1) + 1;
    if (x > mid)  return f(lv-1, x-mid) + (2*pow(2, lv-1)-1) + 1;
}

int main() {
    cin >> n >> x;
    cout << f(n, x) << endl;
}