#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vull = vector<ull>;
using vvull = vector<vull>;
using vvvull = vector<vvull>;

#define REP(i, n, m) for(ll i=n; i<(ll)m; ++i)
#define IREP(i, n, m) for(ll i=n-1; i>=m; --i)
#define rep(i, n) REP(i, 0, n)
#define irep(i, n) IREP(i, n, 0)
#define all(v) v.begin(), v.end()
#define vprint(v) for(auto e:v){cout<<e<<" ";};cout<<endl;
#define vvprint(vv) for(auto v:vv)vprint(v);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll N;
    cin >> N;

    vull S(N), T(N), U(N), V(N);
    rep(i, N) cin >> S[i];
    rep(i, N) cin >> T[i];
    rep(i, N) cin >> U[i];
    rep(i, N) cin >> V[i];

    vvvll t(N, vvll(N, vll(64, -1)));
    bool possible = true;
    rep(i, N){
        rep(j, N) rep(k, 64) if(((U[i]>>k)&1)==((V[j]>>k)&1)) t[i][j][k] = (U[i]>>k) & 1;
        if(S[i]==0){
            rep(j, N) rep(k, 64){
                if(((U[i]>>k)&1)==1){
                    possible &= t[i][j][k]!=0;
                    t[i][j][k] = 1;
                }
            }
        }
        else{
            rep(j, N) rep(k, 64){
                if(((U[i]>>k)&1)==0){
                    possible &= t[i][j][k]!=1;
                    t[i][j][k] = 0;
                }
            }
        }
        if(T[i]==0){
            rep(j, N) rep(k, 64){
                if(((V[i]>>k)&1)==1){
                    possible &= t[j][i][k]!=0;
                    t[j][i][k] = 1;
                }
            }
        }
        else{
            rep(j, N) rep(k, 64){
                if(((V[i]>>k)&1)==0){
                    possible &= t[j][i][k]!=1;
                    t[j][i][k] = 0;
                }
            }
        }
    }
    if(possible){
        rep(i, N) rep(j, N) rep(k, 64) if(t[i][j][k]<0) t[i][j][k] = 0;
        vvll r(N, vll(64, -1)), c(N, vll(64, -1));
        rep(i, 64){
            rep(j, N){
                if(S[j]==0 && ((U[j]>>i)&1)==0){
                    bool found = false;
                    rep(k, N) found |= t[j][k][i]==0;
                    if(!found) r[j][i] = 0;
                }
                else if(S[j]==1 && ((U[j]>>i)&1)==1){
                    bool found = false;
                    rep(k, N) found |= t[j][k][i]==1;
                    if(!found) r[j][i] = 1;
                }
                if(T[j]==0 && ((V[j]>>i)&1)==0){
                    bool found = false;
                    rep(k, N) found |= t[k][j][i]==0;
                    if(!found) c[j][i] = 0;
                }
                else if(T[j]==1 && ((V[j]>>i)&1)==1){
                    bool found = false;
                    rep(k, N) found |= t[k][j][i]==1;
                    if(!found) c[j][i] = 1;
                }
            }
        }
        vvll rcnt(N, vll(64, 0)), ccnt(N, vll(64, 0));
        rep(i, 64){
            rep(j, N){
                rep(k, N){
                    if(t[j][k][i]==0) ++rcnt[j][i];
                    if(t[k][j][i]==0) ++ccnt[j][i];
                }
            }
        }
        rep(i, 64){
            rep(j, N){
                if(r[j][i]==1){
                    rep(k, N){
                        if(t[j][k][i]==0){
                            if(T[k]==0 && ((V[k]>>i)&1)==0 && ccnt[k][i]>=2){
                                t[j][k][i] = 1;
                                ++rcnt[j][i];
                                --ccnt[k][i];
                                break;
                            }
                        }
                    }
                }
            }
            rep(j, N){
                if(c[j][i]==1){
                    rep(k, N){
                        if(t[k][j][i]==0){
                            if(S[k]==0 && ((U[k]>>i)&1)==0 && rcnt[k][i]>=2){
                                t[k][j][i] = 1;
                                --rcnt[k][i];
                                ++ccnt[j][i];
                                break;
                            }
                        }
                    }
                }
            }
        }
        rep(i, 64) rep(j, N){
            ull r = 1-S[j], c = 1-T[j];
            rep(k, N){
                r = S[j]==0? (r&t[j][k][i]) : (r|t[j][k][i]);
                c = T[j]==0? (c&t[k][j][i]) : (c|t[k][j][i]);
            }
            possible &= r==((U[j]>>i)&1) && c==((V[j]>>i)&1);
        }

        if(possible){
            rep(i, N){
                rep(j, N){
                    ull n = 0;
                    irep(k, 64) n = (n<<1) + t[i][j][k];
                    cout << n << " ";
                }
                cout << endl;
            }
        }
        else cout << -1 << endl;
    }
    else cout << -1 << endl;
}
