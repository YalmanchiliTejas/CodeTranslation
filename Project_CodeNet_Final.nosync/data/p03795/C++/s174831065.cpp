#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+5;

int main(){
    int n;
    cin >> n;
    long long ord = n * 800;
    long long y = n / 15 * 200;
    cout << ord - y << "\n";
    return 0;
}
