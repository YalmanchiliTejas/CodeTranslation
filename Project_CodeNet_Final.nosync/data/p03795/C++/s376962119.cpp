#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;


int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int a, b;
    a = 800*n;
    n/=15;
    b = 200*n;
    cout << a-b << endl;
    return 0;
}
