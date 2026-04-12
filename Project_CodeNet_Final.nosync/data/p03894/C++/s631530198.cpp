// 基本テンプレート
 
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
using namespace std;
 
#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define int long long int
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
typedef pair<int, int> pii;
typedef long long ll;
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const ll INF = 1001001001001001LL;
const ll MOD = 1000000007LL;

set<int> S;
int N, Q;
bool used[100010];
int perm[100010], idx[100010];

void ins_elem() {
    int x = idx[1];
    int l = perm[x-1], r = perm[x+1];
    if(1 <= l && l <= N) S.insert(l);
    if(1 <= r && r <= N) S.insert(r);
}

signed main() {
    cin >> N >> Q;
    repq(i,1,N) {
        perm[i] = idx[i] = i;
    }

    rep(i,0,Q) {
        ins_elem();
        int A, B; cin >> A >> B;
        swap(idx[perm[A]], idx[perm[B]]);
        swap(perm[A], perm[B]);
        ins_elem();
    }
    S.insert(1);

    cout << S.size() << endl;
    return 0;
}