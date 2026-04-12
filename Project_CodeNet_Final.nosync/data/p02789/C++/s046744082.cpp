#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

#define MAXINF 1000000005
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define repc(it, x) for(auto it = (x).begin(); it != (x).end(); ++it)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define rrepc(it, x) for(auto it = (x).rbegin(); it != (x).rend(); ++it)
#define all(x) (x).begin(), (x).end()
#define P pair<int, int>

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    if(n == m) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}