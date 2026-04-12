#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin>>N;
    vi S(N),T(N);
    rep(i,N) cin>>S[i];
    rep(i,N) cin>>T[i];
    vector<uint64_t> U(N),V(N);
    rep(i,N) cin>>U[i];
    rep(i,N) cin>>V[i];

    vector<vector<uint64_t> > ans(N, vector<uint64_t>(N,0));

    rep(i,64){
        vi A(N),B(N);
        int flg[2]={0,0};
        rep(j,N){
            bool t = U[j]>>i&1;
            if (t)    A[j]|=1; // 1
            if (S[j]) A[j]|=2; // OR
            if (t) flg[0]|=1; else flg[0]|=2;
        }
        rep(j,N){
            bool t = V[j]>>i&1;
            if (t)    B[j]|=1; // 1
            if (T[j]) B[j]|=2; // OR
            if (t) flg[1]|=1; else flg[1]|=2;
        }
        if (flg[0]==3 || flg[1]==3){
            int c=0;
            if ((flg[0]&flg[1])==2) c=1;
            rep(j,N)rep(k,N){
                int a=A[j], b=B[k];
                if (a>b) swap(a,b);
                if (a==1 && b==2){puts("-1"); return 0;};
                if (a==1 || b==1) ans[j][k] |= 1ULL<<i;
                if ((a&1) && (b&1)) ans[j][k] |= 1ULL<<i;
                if (a==0 && b==3 && c) ans[j][k] |= 1ULL<<i;
            }
        }else if(flg[0]==1 && flg[1]==1){
            rep(j,N)rep(k,N){
                ans[j][k] |= 1ULL<<i;
            }
        }else if(flg[0]==1 || flg[1]==1){
            vector<vector<pi> > blank;
            blank.pb(vector<pi>());
            rep(j,N){
                rep(k,N){
                    int a=A[j], b=B[k];
                    if (a>b) swap(a,b);
                    if (a==1 && b==2){puts("-1"); return 0;};
                    if (a==1 || b==1) ans[j][k] |= 1ULL<<i;
                    if ((a&1) && (b&1)) ans[j][k] |= 1ULL<<i;
                    if (a==0 && b==3){
                        blank.back().emplace_back(j,k);
                    }
                }
                if (blank.back().size()) blank.pb(vector<pi>());
            }

            if (blank[0].empty()) continue;
            blank.pop_back();
            if (blank[0].size()==1 || blank.size()==1){
                puts("-1");
                return 0;
            }
            if (flg[0]==1){
                int B = blank.size();
                rep(j,B){
                    int y,x;
                    if (j==0)
                        tie(y,x) = blank[j][0];
                    else
                        tie(y,x) = blank[j][1];
                    ans[y][x] |= 1ULL<<i;
                }
            }else{
                int B = blank[0].size();
                rep(j,B){
                    int y,x;
                    if (j==0)
                        tie(y,x) = blank[0][j];
                    else
                        tie(y,x) = blank[1][j];
                    ans[y][x] |= 1ULL<<i;
                }
            }
        }
    }

    auto check = [&](){
        rep(i,N){
            uint64_t cur = ans[i][0];
            rep(j,N-1){
                if (S[i]) cur |= ans[i][j+1];
                else cur &= ans[i][j+1];
            }
            if (cur!=U[i]) return false;
        }
        rep(j,N){
            uint64_t cur = ans[0][j];
            rep(i,N-1){
                if (T[j]) cur |= ans[i+1][j];
                else cur &= ans[i+1][j];
            }
            if (cur!=V[j]) return false;
        }
        return true;
    };

    if (!check()){
        puts("-1");
        return 0;
    }

    rep(i,N){
        rep(j,N){
            if (j>0) cout<<" ";
            cout<<ans[i][j];
        }cout<<"\n";
    }
    return 0;
}
