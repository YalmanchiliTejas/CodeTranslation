#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iterator>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

#define rep(i, n, m) for (int i = n; i <= m; i++)
#define Rep(i, n, m) for (int i = m; i >= 1; i--)

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, 1, n) cin >> h[i];
    int ans = 1;
    int high = h[1];
    rep(i, 2, n) {
        if (high <= h[i]) {
            ans++;
            high = h[i];
        }
    }
    cout << ans << endl;
}