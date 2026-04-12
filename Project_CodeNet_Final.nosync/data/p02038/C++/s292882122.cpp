#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<iomanip>
#include<set>
#include<numeric>
#include<sstream>
#include<random>
#include<cassert>
#include<complex>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rrep(i, st, n) for (int i = st; i < n; ++i)
using pii = pair<int, int>;
const int inf = 1e9 + 7;
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {1, -1, 0, 0, -1, 1, 1, -1};
#define ceil(a, b) a / b + !!(a % b)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    queue<char> q;
    int n; cin >> n;
    rep(i, n) {
        char a; cin >> a;
        q.push(a);
        if (i) {
            char a = q.front();
            q.pop();
            char b = q.front();
            q.pop();
            if (a == 'T' && b == 'F') q.push('F');
            else q.push('T');
        }
    }
    cout << q.front() << endl;
}



