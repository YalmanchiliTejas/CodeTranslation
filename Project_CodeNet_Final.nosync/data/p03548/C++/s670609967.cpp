#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <numeric>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repi(i, start, end) for(int i = start; i < end; i++)
#define all(x) (x).begin(), (x).end()
#define debug(x) cout << (x) << endl;
typedef long long ll;
const int MAX = 999999999;

int main(){
    int x, y, z;
    cin >> x >> y >> z;

    if(x < y){
        cout << 0 << endl;
        return 0;
    }

    int cnt = 0;
    while(y * cnt + z * (cnt+1) <= x) cnt++;

    cout << cnt-1 << endl;
}