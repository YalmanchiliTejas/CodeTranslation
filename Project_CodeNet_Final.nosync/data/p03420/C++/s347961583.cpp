#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <random>
#include <climits>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <stack>

#define mod 1000000007
#define INF2 9999999999
#define INF (1<<30)
#define rep(i,n) for(int (i)=0; (i)<(n); (i)++)
#define P pair<int, int>

using namespace std;
using ll = long long;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int DX[] = {1, 1, 0, -1, -1, -1, 0, 1};
int DY[] = {0, -1, -1, -1, 0, 1, 1, 1};

struct edge {int from, to, cost; };

void solve(){
    int n, k;
    ll c=0;
    cin >> n >> k;
    if(k == 0){
        cout << (ll)n*n << endl;
        return;
    }
    for(int i = k; i <= n; i++){
        c += (n/i) * (i-k);
        c += max(0, n%i-k+1); 
    }
    cout << c << endl;
}

int main(){
    solve();
    return 0;
}
