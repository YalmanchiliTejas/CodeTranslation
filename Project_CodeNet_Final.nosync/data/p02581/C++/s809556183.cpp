#include<bits/stdc++.h>

#define ll long long
#define rep(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

#define fi first
#define se second
#define all(A) A.begin(),A.end()

using namespace std;
#define vv vector

/////////////////////////////////////////////////////

#define isIn(x,y) 0<=x&&x<H&&0<=y&&y<W

ll N,N3;
ll A[303030];
ll i, j, k;

void mxin(ll& a,ll b){
    if(a<b)
        a = b;
}


void dpcalc(vv<vv<pair<ll, pll>>>& dp,vv<ll>& odp2,vv<ll>& av,ll& odpmx,ll I){
    ll i, j, k;
    vv<ll> dp2 = odp2;
    ll dpmx = odpmx;

    auto gtdp = [&](ll a, ll b) {
        if(a>b)
            swap(a, b);
        if(dp[a][b].se.fi!=I)
            dp[a][b].se = {I, dp[a][b].fi};
        return dp[a][b].se.se;
    };
    auto stdp = [&](ll a, ll b, ll n) {
        if(a>b)
            swap(a, b);
        if(dp[a][b].se.fi!=I)
            dp[a][b].se = {I, dp[a][b].fi};
        
        mxin(dp[a][b].fi, n);
        mxin(dp2[a], n);
        mxin(dp2[b], n);
        mxin(dpmx, n);
    };
    
    

    rep(i,0,3){
        vv<ll> bv;
        rep(j,0,3){
            if(i!=j)
                bv.push_back(av[j]);
        }
        stdp(bv[0], bv[1], odpmx);
        stdp(bv[0], bv[1], gtdp(av[i], av[i]) + 1);

        
        rep(j,1,N+1){
            stdp(av[i], j, odp2[j]);
            if(bv[0]==bv[1])
                stdp(av[i], j, gtdp(bv[0], j) + 1);
        }
    }
    odp2 = dp2;
    odpmx = dpmx;
}

int main(){
    scanf("%lld", &N);
    N3 = N * 3;
    rep(i,0,N3){
        scanf("%lld", &A[i]);
    }
    vv<ll> Av;
    Av.push_back(A[0]);
    Av.push_back(A[1]);
    rep(i,1,N){
        //cout << A[i * 3 - 1] << A[i * 3] << A[i * 3 + 1] << endl;
        if(A[i*3-1]==A[i*3]&&A[i*3]==A[i*3+1])
            continue;
        rep(j,-1,2){
            Av.push_back(A[i * 3 + j]);
        }
    }
    Av.push_back(A[N3 - 1]);

    vv<vv<pair<ll, pll>>> dp(N + 3, vv<pair<ll, pll>>(N + 3, {-1e15, {0, -1e15}}));
    vv<ll> dp2(N + 3, -1e15);
    ll dpmx = 0;
    if (Av[0] > Av[1])
        swap(Av[0], Av[1]);
    dp[Av[0]][Av[1]] = {N - Av.size() / 3, {0, 0}};
    dpmx = dp2[Av[0]] = dp2[Av[1]] = dp[Av[0]][Av[1]].fi;

    rep(i,2,Av.size()){
        /*
        rep(j,1,N+1){
            rep(k,j,N+1){
                printf("%lld,%lld:%lld\n", j, k, dp[j][k].fi);
            }
        }*/
        if(i+3>Av.size())
            break;
        vv<ll> bv;
        rep(j,0,3){
            bv.push_back(Av[i + j]);
        }
        dpcalc(dp, dp2, bv, dpmx, i);
        i += 2;
        
    }
    ll ln = Av[i];
    ll ans = max(dpmx,dp[ln][ln].fi+1);

    printf("%lld\n", ans);

    return 0;
}