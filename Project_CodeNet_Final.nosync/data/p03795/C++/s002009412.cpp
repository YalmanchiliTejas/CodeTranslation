#include<iostream>
using namespace std;

int n;

int main() {
    cin >> n;
    cout << 800 * n - 200 * (int)(n / 15) << endl;
}

