#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int n;
    int a[200010];
    int even[100010], odd[100010];
    int ecnt = 0, ocnt = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if ((i+1)%2) {
            odd[ocnt] = a[i];
            ocnt++;
        }
        else {
            even[ecnt] = a[i];
            ecnt++;
        }
    }
    if (n%2) {
        for (int i = ocnt-1; i >= 0; i--) {
            cout << odd[i] << " ";
        }
        for (int i = 0; i < ecnt; i++) {
            cout << even[i] << " ";
        }
        cout << endl;
    }
    else {
        for (int i = ecnt-1; i >= 0; i--) {
            cout << even[i] << " ";
        }
        for (int i = 0; i < ocnt; i++) {
            cout << odd[i] << " ";
        }
        cout << endl;
    }
}
