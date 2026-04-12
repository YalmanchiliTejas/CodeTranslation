#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

const int oo = 1e9 + 7;
const ll mod = 1e9 + 7, maxn = 1000001;
const double PI = acos(-1);
int dp[110][11][3], k, n;
string num;

int solve(int pos, int nz, bool less){
    int& tmp = dp[pos][nz][less];
    if (pos == n) return nz == k;
    if (nz > k) return 0;
    if (tmp != -1) return tmp;

    tmp = 0;
    int dig = num[pos] - '0';
    if (less){

        for (int i=0; i<10; i++){
            tmp += solve(pos+1, nz + (i > 0), true);
        }
    }

    else {
        for (int i=0; i<dig; i++){
            tmp += solve(pos+1, nz + (i > 0), true);
        }
        tmp += solve(pos + 1, nz + (dig > 0), false);
    }
    return tmp;
}

int main (){
    ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    cin >> num >> k;
    n = num.size();

    cout << solve(0, 0, 0) << endl;
    return 0;
}