#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (long long i = 0; i < (1 << n); i++) {
        cout << i << ":";
        for (long long j = 0; j < n; j++) {
            if (i & (1 << j)) { cout << " " << j;}
        }
        cout << endl;
    }
}
