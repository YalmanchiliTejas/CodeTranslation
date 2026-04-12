#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int n;
    long long waru = 1000000007;

    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++) cin >> vec.at(i);

    int kekka = 0;
    int x = 0;

    for (int i = 0; i < n; i++) {
        kekka = (kekka + (long long) vec.at(i) * x) % waru;
        x = (x + vec.at(i)) % waru;
    }

    cout << kekka;
    //
}