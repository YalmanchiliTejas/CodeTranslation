#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define sizeOf(A) (sizeof(A))/(sizeof(A[0]))
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);

int main() {
    fastio;

    int a, b, c;
    cin >> a >> b >> c;
    int x = 100*a + 10*b + c;
    if (x % 4) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
    return 0;
}
