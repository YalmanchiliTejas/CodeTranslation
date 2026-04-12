#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define INF 120000000

using namespace std;

typedef pair<int, int> P;
typedef long long int LL;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    x -= z;
    cout << x / (y + z) << endl;

    return 0;
}
