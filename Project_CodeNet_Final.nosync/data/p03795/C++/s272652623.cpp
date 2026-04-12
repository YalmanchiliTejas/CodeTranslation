#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repr(i, n) for(int i = (int)(n); i >= 0; i--)
#define repm(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define repmr(i, m, n) for(int i = (int)(n); i >= (int)(m); i--)
#define all(x) (x).begin(),(x).end()
#define inf 2e9

using namespace std;
typedef long long int lli;
typedef long long ll;

int n,q;
vector<vector<int>> tree(200000, vector<int>());

int main() {
    int n;
    cin >> n;

    int x = 800*n;
    int y = (n/15) * 200;

    cout << x-y << endl;
}
