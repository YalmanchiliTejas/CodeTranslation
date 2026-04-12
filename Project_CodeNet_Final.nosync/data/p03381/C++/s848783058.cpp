#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 2e5;

int n;
int x[N_MAX + 2], aux[N_MAX + 2];

int med[3];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
        aux[i] = x[i];
    }

    sort(aux + 1, aux + n + 1);
    med[0] = aux[n / 2];
    med[1] = aux[n / 2 + 1];

    for(int i = 1; i <= n; i++) {
        if(x[i] < med[1])
            cout << med[1];
        else
            cout << med[0];
        cout << '\n';
    }

    return 0;
}
