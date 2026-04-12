
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    if (n == 3 || n == 5 || n == 7)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}

