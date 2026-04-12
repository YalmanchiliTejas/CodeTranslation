#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(long long i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const int mod = 1000000007;

ll s[505];
ll t[505];
ull u[505];
ull v[505];
ll su[505];
ll sv[505];
ll ans[505][505][64];

void f() {
    vector<ll> a;
    a[0] = 1;
}

int main(){
    ll n;
    cin >> n;
    rep(i, n) cin >> s[i];
    rep(i, n) cin >> t[i];
    rep(i, n) cin >> u[i];
    rep(i, n) cin >> v[i];

    rep(k, 64) {
        
        rep(i, n) {
            rep(j, n) {
                ans[i][j][k] = -1LL;
            }
        }
        
        vector<ll> iu(n);
        vector<ll> iv(n);
        vector<ll> ru;
        vector<ll> rv;
        rep(i, n) {
            iu[i] = (u[i]>>k)&1;
            iv[i] = (v[i]>>k)&1;
            if (s[i]==0 && iu[i]==1) {
                rep(j, n) {
                    if (ans[i][j][k]==0) {
                        cout << "-1" << endl;
                        return 0;
                    }
                    ans[i][j][k] = 1LL;
                }
            }
            else if (s[i]==1 && iu[i]==0) {
                rep(j, n) {
                    if (ans[i][j][k]==1) {
                        cout << "-1" << endl;
                        return 0;
                    }
                    ans[i][j][k] = 0LL;
                }
            }
            else ru.push_back(i);

            if (t[i]==0 && iv[i]==1) {
                rep(j, n) {
                    if (ans[j][i][k]==0) {
                        cout << "-1" << endl;
                        return 0;
                    }
                    ans[j][i][k] = 1LL;
                }
            }
            else if (t[i]==1 && iv[i]==0) {
                rep(j, n) {
                    if (ans[j][i][k]==1) {
                        cout << "-1" << endl;
                        return 0;
                    }
                    ans[j][i][k] = 0LL;
                }
            }
            else rv.push_back(i);
        }
        if (ru.size()==0 || rv.size()==0) {;}
        else if (ru.size()>=2 && rv.size()>=2) {
            rep(i, ru.size()) rep(j, rv.size()) {
                ans[ru[i]][rv[j]][k] = (i+j)%2;
            }
        }
        else if (ru.size()==1) {
            vector<ll> remain;
            rep(j, rv.size()) {
                ll sum = 0;
                rep(i, n) {
                    if (i==ru[0]) continue;
                    sum += ans[i][rv[j]][k];
                }
                if (t[rv[j]]==0 && iv[rv[j]]==0 && sum==n-1) ans[ru[0]][rv[j]][k] = 0LL;
                if (t[rv[j]]==1 && iv[rv[j]]==1 && sum==0) ans[ru[0]][rv[j]][k] = 1LL; 
            }
            ll sum = 0;
            rep(j, n) {
                if (ans[ru[0]][j][k]==-1) remain.push_back(j);
                else sum += ans[ru[0]][j][k];
            }
            if (remain.size()==0) {
                if (s[ru[0]]==0 && iu[ru[0]]==0 && sum==n) {
                    cout << "-1" << endl;
                    return 0;
                }
                if (s[ru[0]]==1 && iu[ru[0]]==1 && sum==0) {
                    cout << "-1" << endl;
                    return 0;
                }
            }
            else {
                rep(j, remain.size()) {
                    ans[ru[0]][remain[j]][k] = iu[ru[0]];
                }
            }
        }
        else if (rv.size()==1) {
            vector<ll> remain;
            rep(i, ru.size()) {
                ll sum = 0;
                rep(j, n) {
                    if (j==rv[0]) continue;
                    sum += ans[ru[i]][j][k];
                }
                if (s[ru[i]]==0 && iu[ru[i]]==0 && sum==n-1) ans[ru[i]][rv[0]][k] = 0LL;
                if (s[ru[i]]==1 && iu[ru[i]]==1 && sum==0) ans[ru[i]][rv[0]][k] = 1LL; 
            }
            ll sum = 0;
            rep(i, n) {
                if (ans[i][rv[0]][k]==-1) remain.push_back(i);
                else sum += ans[i][rv[0]][k];
            }
            if (remain.size()==0) {
                if (t[rv[0]]==0 && iv[rv[0]]==0 && sum==n) {
                    cout << "-1" << endl;
                    return 0;
                }
                if (t[rv[0]]==1 && iv[rv[0]]==1 && sum==0) {
                    cout << "-1" << endl;
                    return 0;
                }
            }
            else {
                rep(i, remain.size()) {
                    ans[remain[i]][rv[0]][k] = iv[rv[0]];
                }
            }
        }
        bool ok = true;
        rep(i, n) {
            ll sum = 0;
            rep (j, n) {
                sum += ans[i][j][k];
            }
            if (s[i]==1 && iu[i]==1 && sum==0) ok = false;
            if (s[i]==0 && iu[i]==0 && sum==n) ok = false;
            sum = 0;
            rep(j, n) {
                sum += ans[j][i][k];
            }
            if (t[i]==1 && iv[i]==1 && sum==0) ok = false;
            if (t[i]==0 && iv[i]==0 && sum==n) ok = false;
        }
        if (!ok) {
            cout << "-1" << endl;
            return 0;
        }
    }
    
    //cout << "aaa " << ans[0][0][0] << " " << ans[0][1][0] << " " << ans[1][0][0] << " " << ans[1][1][0] << endl;
    
    
    rep(i, n) {
        rep(j, n) {
            ull v = 0;
            ull now = 1;
            ull two = 2;
            rep(k, 64) {
                //v |= (ans[i][j][k]<<k);
                if (ans[i][j][k]==1) {
                    v += now;
                }
                now *= two;
            }
            cout << v;
            if (j!=n-1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
