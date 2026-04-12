#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;

int main() {
    cin >> N;
    
    int x = 800 * N;
    int y = 200 * (N / 15);

    cout << x - y << endl;

    return 0;
}
