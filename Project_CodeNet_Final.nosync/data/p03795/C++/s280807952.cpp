#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << ": " << x << endl;
#define ll long long

int main() {
    int n;
    cin >> n;
    int x = n * 800;
    int y = 200 * (n / 15);

    cout << x - y << endl;

    return 0;
}