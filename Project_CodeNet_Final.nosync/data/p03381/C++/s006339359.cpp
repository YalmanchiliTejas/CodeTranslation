#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x[n];
    int y[n];
    for(int i = 0; i < n; i++) {
       cin >> x[i]; 
       y[i] = x[i];
    }
    sort(x, x+n);
    int left = x[n/2 - 1];
    int right = x[n/2];
    for(int i = 0; i < n; i++) {
        if (y[i] <= left) {
            cout << right << endl;
        } else {
            cout << left << endl;
        }
    }
    return 0;
}