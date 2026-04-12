#include <iostream>

using namespace std;

const int N=2e5+5;
int a[N];
int n;

int ind[N];

int main() {
        cin >> n;
        for (int i=n-1; i>=0; i--) {
                if (i%2 == n%2) {
                        ind[(n+i)/2] = i;
                } else {
                        ind[(n-1-i)/2] = i;
                }
        }

        for (int i=0; i<n; i++) {
                cin >> a[i];
        }

        for (int i=0; i<n; i++) {
                cout << a[ind[i]] << " ";
        }

        cout << "\n";
}