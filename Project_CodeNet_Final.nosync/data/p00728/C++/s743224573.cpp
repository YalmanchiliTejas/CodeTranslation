#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(true) {
        int n;
        cin >> n;
        if(n == 0) break;
        int maxi = -1;
        int mini = 1e9;
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            int in;
            cin >> in;
            maxi = max(maxi, in);
            mini = min(mini, in);
            sum += in;
        }
        cout << (sum - maxi - mini) / (n - 2) << endl;

    }
    return 0;
}
