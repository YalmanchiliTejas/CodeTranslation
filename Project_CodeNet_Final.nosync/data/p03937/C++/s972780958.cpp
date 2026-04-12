#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double
#define zeros(x) x^(x-1)&x
#define pii pair<ll,ll>
#define cd complex<double>
#define dbg(x) cerr<<#x<<": "<<x<<endl;ll
#define Nmax 400005
#define OFF 100001
using namespace std;

ll n,m,c;
char mat[55][55];

int main()
{
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> mat[i]+1;

    int ok = 1;
    c = 1;
    for (int i=1;i<=n;i++){
        if (mat[i][c]!='#') ok = 0;
        mat[i][c] = '.';
        while (c < m && mat[i][c+1] == '#'){
            c++;
            mat[i][c] = '.';
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (mat[i][j] == '#') ok = 0;
        }
    }
    if (ok) cout << "Possible\n";
    else cout << "Impossible\n";

    return 0;
}
