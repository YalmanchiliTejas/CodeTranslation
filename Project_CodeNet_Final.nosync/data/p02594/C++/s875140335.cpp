#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = 1000 * 1000 * 1000 + 7 ;
vll mul_mat(vll a , vll b) {
    vll res(2 , vl(2,0)) ;
    int n = 2 ;
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                res[i][j] += a[i][k] * b[k][j] ;
                res[i][j] %= Mod ;
            }
        }
    }

    return res ;
}
void solve() {
    int n ;
    cin >> n ;
    if(n >= 30 ) {
        cout << "Yes" << endl;
    }else
        cout << "No" << endl;
}


int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    //cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}