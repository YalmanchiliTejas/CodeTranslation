# pragma GCC optimize("Ofast")
# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size)
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
using namespace std;
using lint = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int h,w; cin >> h >> w;
    vector<string> a(h);
    vector<string> ans(h);
    rep(i,h) cin >> a[i];
    vector<vector<int> > map(h,vector<int> (w,1)); 
    //行の削除
    rep(i,h){
        rep(j,w){
            if(a[i][j]=='#') break;
            if(j==w-1){
                rep(k,w){
                    map[i][k] = 0;
                }
            }
        }
    }

    //列の削除
    rep(i,w){
        rep(j,h){
            if(a[j][i]=='#') break;
            if(j==h-1){
                rep(k,h){
                    map[k][i] = 0;
                }
            }
        }
    }
    int k = 0;
    rep(i,h){
        bool judge = true;
        rep(j,w){
            if(map[i][j]==1){
                judge = false;
                ans[k] += a[i][j];
            }
        }
        if(judge == false)++k;
    }

    rep(i,k){
            cout << ans[i];
        cout << endl;
    }

    return 0;
}