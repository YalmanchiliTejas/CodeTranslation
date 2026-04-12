#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void printVector(vector<int> v) {
    for (auto x : v) {
        cout << x << ' ';
    }
    cout << '\n';
}

void printArray(ll A[], int size) {
    for (int i = 0; i <= size - 1; i++) cout << A[i] << ' ';
}

int main() {
    int n;
    cin >> n;
    int maior = 0;
    int tot = 0;
    for (int i = 0; i <= n - 1; i++) {
        int a;
        cin >> a;
        if (a >= maior) {
            maior = a;
            tot++;
        }
    }
    cout << tot << '\n';
    return 0;
}