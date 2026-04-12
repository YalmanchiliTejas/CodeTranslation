#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> i_i;
typedef pair<ll, ll> l_l;
 
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int n, h[111];
int mx = -1, cnt = 0;
int main() {
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> h[i];
        if (mx<=h[i]) {
            cnt++;
            mx = h[i];
        }
    }

    cout << cnt << endl;
}