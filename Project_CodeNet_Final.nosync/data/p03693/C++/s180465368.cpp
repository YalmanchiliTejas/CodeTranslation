#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1001001001;
const int MOD = 1e9 + 7;

int main(){
    int r, g, b;
    cin >> r >> g >> b;

    int N = 100 * r + 10 * g + b;

    if (N % 4) puts("NO");
    else puts("YES");
}