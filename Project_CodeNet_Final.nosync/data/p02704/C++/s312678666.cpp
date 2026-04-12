#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
typedef unsigned long long ll;
typedef pair<ll,ll> pr;
typedef vector<ll> vc;
typedef unordered_map<ll,ll> umap;
#define pb emplace_back
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define reps(i,v) for(ll i=0;i<v.size();i++)
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
const ll mod = 1e9+7;

int main() {
    // your code goes here
    ll n,tws=1,uu,vv;
    ll s[505],t[505];
    ll u[505],v[505];
    ll c[70][505],d[70][505];
    ll ans[505][505]={0};
    cin >> n;
    rep(i,1,n){
        cin >> s[i];
    }
    rep(i,1,n){
        cin >> t[i];
    }
    rep(i,1,n){
        cin >> u[i];
        if(i==1) uu=u[i];
        rep(j,0,63){
            c[j][i] = u[i]%2;
            u[i] = u[i]/2;
        }
    }
    rep(i,1,n){
        cin >> v[i];
        if(i==1) vv=v[i];
        rep(j,0,63){
            d[j][i] = v[i]%2;
            v[i] = v[i]/2;
        }
    }
    if(n==1){
        if(uu!=vv) cout << -1 << endl;
        else cout << uu << endl;
        return 0;
    }
    rep(k,0,63){
        vc ts,ys;
        ll m[505][505];
        bool tz=0,ti=0,yi=0,yz=0;
        ll ch=0;
        rep(i,1,n){
            rep(j,1,n){
                m[i][j]=2;
            }
        }
        rep(i,1,n){
            if(s[i]==1&&c[k][i]==0){
                rep(j,1,n){
                    if(m[i][j]==1){
                        cout << -1 << endl;
                        return 0;
                    }
                    m[i][j] = 0;
                }
                yz=true;
            } else if(s[i]==0&&c[k][i]==1){
                rep(j,1,n){
                    if(m[i][j]==0){
                        cout << -1 << endl;
                        return 0;
                    }
                    m[i][j] = 1;
                }
                yi=true;
            } else {
                ys.pb(i);
            }
            if(t[i]==1&&d[k][i]==0){
                rep(j,1,n){
                    if(m[j][i]==1){
                        cout << -1 << endl;
                        return 0;
                    }
                    m[j][i] = 0;
                }
                tz=true;
            } else if(t[i]==0&&d[k][i]==1){
                rep(j,1,n){
                    if(m[j][i]==0){
                        cout << -1 << endl;
                        return 0;
                    }
                    m[j][i] = 1;
                }
                ti=true;
            } else {
                ts.pb(i);
            }
            
        }
        //rep(i,1,n){ rep(j,1,n){ cout << m[i][j]; if(j!=n) cout << " ";  else cout << endl;} }
        if(yi&&yz){
            rep(i,1,n){
                rep(j,1,n){
                    if(i==1){
                        if(m[j][i]==2) m[j][i]=1;
                    } else {
                        if(m[j][i]==2) m[j][i]=0;
                    }
                }
            }
        } else if(ti&&tz){
            rep(i,1,n){
                rep(j,1,n){
                    if(i==1){
                        if(m[i][j]==2) m[i][j]=1;
                    } else {
                        if(m[i][j]==2) m[i][j]=0;
                    }
                }
            }
        } else if(tz&&yz){
            rep(i,1,n){
                rep(j,1,n){
                    if(m[i][j]==2) m[i][j]=1;
                }
            }
        } else if(ti&&yi){
            rep(i,1,n){
                rep(j,1,n){
                    if(m[i][j]==2) m[i][j]=0;
                }
            }
        } else if(yi){
            if(ys.size()>1){
            reps(i,ys){
                m[ys[i]][ts[i]]=0;
            }
            rep(i,ys.size(),ts.size()-1){
                m[ys[0]][ts[i]]=0;
            }
            rep(i,1,n){
                rep(j,1,n){
                    if(m[i][j]==2) m[i][j]=1;
                }
            }
            } else if(ys.size()==1){
            	ll zs=0;
                rep(j,1,n){
                    if(t[j]==0&&d[k][j]==0){
                    	m[ys[0]][j]=0;
                    	zs=1;
                    }
                    else m[ys[0]][j]=1;
                }
                if(zs==0) m[ys[0]][1]=0;
            }
        } else if(yz) {
            if(ys.size()>1){
            reps(i,ys){
                m[ys[i]][ts[i]]=1;
            }
            rep(i,ys.size(),ts.size()-1){
                m[ys[0]][ts[i]]=1;
            }
            rep(i,1,n){
                rep(j,1,n){
                    if(m[i][j]==2) m[i][j]=0;
                }
            }
            } else if(ys.size()==1){
            	ll os=0;
                rep(j,1,n){
                    if(t[j]==1&&d[k][j]==1){
                    	m[ys[0]][j]=1;
                    	os=1;
                    }
                    else m[ys[0]][j]=0;
                }
                if(os==0) m[ys[0]][1]=1;
            }
        } else if(ti) {
            if(ts.size()>1){
            reps(i,ts){
                m[ys[i]][ts[i]]=0;
            }
            rep(i,ts.size(),ys.size()-1){
                m[ys[i]][ts[0]]=0;
            }
            rep(i,1,n){
                rep(j,1,n){
                    if(m[i][j]==2) m[i][j]=1;
                }
            }
            } else if(ts.size()==1){
            	ll zs=0;
                rep(j,1,n){
                    if(s[j]==0&&c[k][j]==0){
                    	m[j][ts[0]]=0;
                    	zs=1;
                    }
                    else m[j][ts[0]]=1;
                }
                if(zs==0) m[1][ts[0]]=0;
            }
        } else if(tz) {
            if(ts.size()>1){
            reps(i,ts){
                m[ys[i]][ts[i]]=1;
            }
            rep(i,ts.size(),ys.size()-1){
                m[ys[i]][ts[0]]=1;
            }
            rep(i,1,n){
                rep(j,1,n){
                    if(m[i][j]==2) m[i][j]=0;
                }
            }
            } else if(ts.size()==1){
            	ll os=0;
                rep(j,1,n){
                    if(s[j]==1&&c[k][j]==1){
                    	m[j][ts[0]]=1;
                    	os=1;
                    }
                    else m[j][ts[0]]=0;
                }
                if(os==0) m[1][ts[0]]=1;
            }
        } else {
            rep(i,1,n){
                rep(j,1,n){
                    if(i==j) m[i][j]=0;
                    else m[i][j]=1;
                }
            }
        }
        rep(i,1,n){
            if(s[i]==1){
                ch = 0;
                rep(j,1,n) if(m[i][j]==1) ch = 1;
                if(ch!=c[k][i]){
                    cout << -1 << endl;
                    return 0;
                }
            } else {
                ch = 1;
                rep(j,1,n) if(m[i][j]==0) ch = 0;
                if(ch!=c[k][i]){
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
        rep(j,1,n){
            if(t[j]==1){
                ch = 0;
                rep(i,1,n) if(m[i][j]==1) ch = 1;
                if(ch!=d[k][j]){
                    cout << -1 << endl;
                    return 0;
                }
            } else {
                ch = 1;
                rep(i,1,n) if(m[i][j]==0) ch = 0;
                if(ch!=d[k][j]){
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
        rep(i,1,n){
            rep(j,1,n){
                ans[i][j] += m[i][j] * tws;
            }
        }
        tws *= 2;
    }
    //rep(i,1,n){ rep(j,1,n){ cout << m[i][j]; if(j!=n) cout << " ";  else cout << endl;} }
    rep(i,1,n){
        rep(j,1,n){
            cout << ans[i][j];
            if(j!=n) cout << " ";
            else cout << endl;
        }
    }
    return 0;
}