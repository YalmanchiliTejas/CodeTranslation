#include<cstring>
#include<iostream>
#include<cstdlib>
#include<string>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (n == k) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}