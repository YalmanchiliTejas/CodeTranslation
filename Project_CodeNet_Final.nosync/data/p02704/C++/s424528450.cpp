#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    ll n;
    cin >> n;
    int s[n], t[n];
    rep(i,n)cin >> s[i];
    rep(i,n)cin >> t[i];
    unsigned long long u[n], v[n];
    rep(i,n)cin >> u[i];
    rep(i,n)cin >> v[i];

    unsigned long long a[n][n];
    rep(i,n)rep(j,n)a[i][j] = 0;

    rep(i,n){
        rep(j,n){
            if(s[i] == 0 && t[j] == 0){
                a[i][j] = (u[i] | v[j]);
            }
            if(s[i] == 0 && t[j] == 1){
                a[i][j] = u[i];
            }
            if(s[i] == 1 && t[j] == 0){
                a[i][j] = v[j];
            }
            if(s[i] == 1 && t[j] == 1){
                a[i][j] = (u[i] & v[j]);
            }
        }
    }

    /*
    rep(i,n){
        rep(j,n){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    */

    unsigned long long b[n] = {}, c[n] = {};

    rep(i,n){
        b[i] = a[i][0];
        rep(j,n){
            if(s[i] == 0) b[i] &= a[i][j];
            else b[i] |= a[i][j];
        }
        if(b[i] > u[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    rep(j,n){
        c[j] = a[0][j];
        rep(i,n){
            if(t[j] == 0) c[j] &= a[i][j];
            else c[j] |= a[i][j];
        }
        if(c[j] > v[j]){
            cout << -1 << endl;
            return 0;
        }
    }

    int ss0 = -1, ss1 = -1, tt0 = -1, tt1 = -1;

    rep(i,n){
        if(s[i] == 0){
            if(ss0 == -1){
                ss0 = i;
            }else{
                ss1 = i;
            }
        }
    }
    rep(i,n){
        if(t[i] == 0){
            if(tt0 == -1){
                tt0 = i;
            }else{
                tt1 = i;
            }
        }
    }

    int lasts = -1, lastt = -1;
    drep(i,n){
        if(s[i] == 1){
            lasts = i;
            break;
        }
    }
    drep(i,n){
        if(t[i] == 1){
            lastt = i;
            break;
        }
    }

    rep(i,n){
        if(s[i] == 1){
            unsigned long x = (u[i] ^ b[i]);
            if(tt0 == -1)continue;
            if(i == lasts){
                if(tt1 == -1) a[i][tt0] |= x;
                else a[i][tt1] |= x;
            }else{
                a[i][tt0] |= x;
            }
        }
    }

    rep(i,n){
        if(t[i] == 1){
            unsigned long x = (v[i] ^ c[i]);
            if(ss0 == -1)continue;
            if(i == lastt){
                if(ss1 == -1)a[ss0][i] |= x;
                else a[ss1][i] |= x;
            }else{
                a[ss0][i] |= x;
            }
        }
    }


    // cout << "OK" << endl;

    rep(i,n){
        b[i] = a[i][0];
        rep(j,n){
            if(s[i] == 0) b[i] &= a[i][j];
            else b[i] |= a[i][j];
        }
        if(b[i] != u[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    rep(j,n){
        c[j] = a[0][j];
        rep(i,n){
            if(t[j] == 0) c[j] &= a[i][j];
            else c[j] |= a[i][j];
        }
        if(c[j] != v[j]){
            cout << -1 << endl;
            return 0;
        }
    }

    rep(i,n){
        rep(j,n){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }

}


