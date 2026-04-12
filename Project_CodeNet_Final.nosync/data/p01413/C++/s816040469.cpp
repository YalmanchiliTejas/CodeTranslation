#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define each(a, b) for(auto (a): (b))
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define pb push_back
#define show(x) cout <<#x<<" = "<<(x)<<endl
#define spair(p) cout <<#p<<": "<<p.fi<<" "<<p.se<<endl
#define svec(v) cout<<#v<<":";rep(kbrni,v.size())cout<<" "<<v[kbrni];cout<<endl
#define sset(s) cout<<#s<<":";each(kbrni,s)cout <<" "<<kbrni;cout<<endl

using namespace std;

typedef pair<int,int>P;

ll dp[1<<8][8]; //????????????????????¨??????
ll dp2[8][10005]; //j????????????????????§??§??????k??\?????¨????????¨????????????????????§???
ll res[1<<7];
ll dp3[1<<8][10005];    //i??????????????§??????j??\?????¨????????¨????????????????????§???
map<string,int> mp;
vector<P> goods;    //??????,??????
vector<P> kind[7]; //?¨????,??????
vector<P> pos;   //????????§?¨?

int main()
{
    int n,m,w,t;
    cin >> n >> m >> w >> t;
    rep(i,m){
        string s;
        int weight;
        int value;
        cin >> s >> weight >> value;
        mp[s] = i;
        goods.pb(P(weight,value));
    }
    rep(i,n){
        int l,x,y;
        cin >> l >> x >> y;
        pos.pb(P(x,y));
        rep(j,l){
            string s;
            int v;
            cin >> s >> v;
            kind[i].pb(P(mp[s],v));
        }
    }
    rep(i,1<<(n+1)){
        rep(j,n+1){
            dp[i][j] = INF;
        }
    }
    pos.pb(P(0,0));
    dp[0][n] = 0;   //?????´??????n??¨??????
    rep(i,(1<<(n+1))){
        rep(j,n+1){
            rep(k,n+1){
                if(!(i & (1 << k))){
                    P p1 = pos[j];
                    P p2 = pos[k];
                    int dir = abs(p1.fi - p2.fi) + abs(p1.se - p2.se);
                    // if((i | (1 << k)) == 5 && j == 1){
                    //     cout << "!!!\n";
                    //     cout << i << " " << j << " " << k << " " << dp[i][k] << " " << dir << endl;
                    // }
                    dp[i | (1 << k)][j] = min(dp[i | (1 << k)][j],dp[i][k]+dir);
                    // if((i | (1 << k)) == 5 && j == 1){
                    //     cout << "ans\n";
                    //     cout << dp[i | (1 << k)][j] << endl;
                    // }
                }
            }
        }
    }
    // rep(i,(1<<(n+1))){
    //     rep(j,n+1){
    //         cout << i << " " << j << " " << dp[i][j] << endl;
    //     }
    // }
    rep(i,(1 << n)){
        vector<int> vec(m,0);
        rep(j,n){
            if(i & (1 << j)){
                rep(k,kind[j].size()){
                    vec[kind[j][k].fi] = max(vec[kind[j][k].fi],goods[kind[j][k].fi].se - kind[j][k].se);
                }
            }
        }
        rep(j,m){
            rep(k,w+1){
                if(vec[j] > 0 && k-goods[j].fi>=0){
                    dp2[j+1][k] = max(dp2[j][k],dp2[j+1][k-goods[j].fi] + vec[j]);
                    // if(i == 1 && j == 1){
                    //     cout << dp2[i][j+1][k] << endl;
                    // }
                }else{
                    dp2[j+1][k] = dp2[j][k];
                }
            }
        }
        res[i] = dp2[m][w];
    }
    // rep(i,(1 << n)){
    //     rep(j,m+1){
    //         rep(k,w+1){
    //             cout << i << " " << j << " " << k << " " << dp2[i][j][k] << endl;
    //         }
    //     }
    // }
    rep(i,(1 << n)){
        rep(j,t+1){
            if(j - dp[i | (1 << n)][n] >= 0){
                dp3[i+1][j] = max(dp3[i][j],dp3[i+1][j-dp[i|(1<<n)][n]] + res[i]);
            }else{
                dp3[i+1][j] = dp3[i][j];
            }
        }
    }
    cout << dp3[(1 << n)][t] << endl;
    return 0;
}