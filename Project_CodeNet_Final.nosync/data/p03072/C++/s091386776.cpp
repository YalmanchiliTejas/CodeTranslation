#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <stdlib.h>
#include <deque>  
#include <iomanip>

using namespace std;

using ll = long long;
#define INF 1e9
#define MOD 1e9 + 7
#define rep(i, n) for(int i = 0; i < n; i++)
#define loop(i, a, n) for(int i = a; i < n; i++)
#define all(in) in.begin(), in.end()
int main(){
    int N;
    cin >> N;
    int h[N];
    rep(i, N)cin >> h[i];
    int ans = 1;
    int high = h[0];
    loop(i, 1, N){
        if(h[i] >= high) ans++;
        high = max(high, h[i]);
    }
    cout << ans << endl;
    return 0;
}