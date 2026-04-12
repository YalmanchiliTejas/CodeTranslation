#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <bitset>
#include <sstream>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <climits>
using namespace std;

#define eps 1e-8
#define mod 1000000007
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int j = 0;
    for (int i = n - 1; i >= 0; i -= 2) {
        b[j++] = a[i];
    }
    for (int i = n % 2 ? 1 : 0; i < n; i += 2) {
        b[j++] = a[i];
    }
    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << b[i];
    }

    return 0;
}