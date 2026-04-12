#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <numeric>
#include <climits>
#include <math.h>
#include <memory.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for(int i = (k); i < (int)(n); i++)
using namespace std;
using ll = long long;
int N, M;
int cnt = 0;
ll ans = 0LL;
int i_index;
int tmp;
int dh[4] = {1, 0, -1, 0};
int dw[4] = {0, 1, 0, -1};
string board[64];
string a[64];

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int minv = 2 * C * 0 + max(X - 0, 0) * A + max(Y - 0, 0) * B;
    rrep(k, 1 , max(X + 1, Y + 1)){
        tmp = 2 * C * k + max(X - k, 0) * A + max(Y - k, 0) * B;
        minv = min(minv, tmp);
    }
    cout << minv << endl;
    return 0;
}