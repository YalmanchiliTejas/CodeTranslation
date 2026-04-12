#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>

using namespace std;

typedef long long ll;

#define rep(i,n)  for(int i=0;i<(n);++i)
#define all(x) (x).begin(),(x).end()

ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }

const int mod = 1000000007;
const int INF = 1001001001;

int graph[10][10];

int main() {
    int n, m;
    cin >> n >> m;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    int array[] = {0, 1, 2, 3, 4, 5, 6, 7};

    int ans = 0;

    do {
        bool flag = true;
        for (int i = 1; i < n; i++) {
            if(graph[array[i-1]][array[i]] != 1) {
                flag = false;
                break;
            }
        }
        if(flag) ans += 1;
    }while (next_permutation(array+1, array + n));

    cout << ans << endl;
}