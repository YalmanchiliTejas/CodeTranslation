#include <bits/stdc++.h>
using namespace std;

#define MN 100000
#define FOR(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
#define f first
#define s second
#define pb push_back


int main() {
    int r, g, b;
    cin >> r >> g >> b;
    int total = (r * 100) + (g * 10) + (b);
    if (total % 4) {cout << "NO\n";}
    else {cout << "YES\n";} 
}

