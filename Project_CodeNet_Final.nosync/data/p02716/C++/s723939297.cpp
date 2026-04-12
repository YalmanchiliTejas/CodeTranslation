#include<bits/stdc++.h>
using namespace std;


#define li          long long int
#define rep(i,to)   for(li i=0;i<((li)(to));i++)
#define repp(i,start,to)    for(li i=(li)(start);i<((li)(to));i++)
#define pb          push_back
#define sz(v)       ((li)(v).size())
#define bgn(v)      ((v).begin())
#define eend(v)     ((v).end())
#define allof(v)    (v).begin(), (v).end()
#define dodp(v,n)       memset(v,(li)n,sizeof(v))
#define bit(n)      (1ll<<(li)(n))
#define mp(a,b)     make_pair(a,b)
#define rin rep(i,n)
#define EPS 1e-12
#define ETOL 1e-8
#define MOD 1000000007
typedef pair<li, li> PI;

#define INF bit(60)

#define DBGP 1


#define idp if(DBGP)
#define F first
#define S second
#define p2(a,b)     idp cout<<a<<"\t"<<b<<endl
#define p3(a,b,c)       idp cout<<a<<"\t"<<b<<"\t"<<c<<endl
#define p4(a,b,c,d)     idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl
#define p5(a,b,c,d,e)       idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<endl
#define p6(a,b,c,d,e,f)     idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<endl
#define p7(a,b,c,d,e,f,g)       idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<endl
#define p8(a,b,c,d,e,f,g,h)     idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<"\t"<<h<<endl
#define p9(a,b,c,d,e,f,g,h,i)       idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<"\t"<<h<<"\t"<<i<<endl
#define p10(a,b,c,d,e,f,g,h,i,j)        idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<"\t"<<h<<"\t"<<i<<"\t"<<j<<endl
#define foreach(it,v)   for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define p2p(x)      idp p2((x).F, (x).S)
#define dump(x,n)   idp{rep(i,n){cout<<x[i]<<" ";}puts("");}
#define dump2(x,n)  idp{rep(i,n){cout<<"["<<x[i].F<<" , "<<x[i].S<<"] ";}puts("");}
#define dumpi(x)    idp{foreach(it, x){cout<<(*it)<<" ";}puts("");}
#define dumpi2(x)   idp{foreach(it, x){cout<<"["<<(it)->F<<" , "<<(it)->S<<"] ";}puts("");}

#define read2d(a,w,h)   rep(i,h)rep(j,w)cin>>a[i][j]
#define dump2d(a,w,h)   rep(i,h){rep(j,w)cout<<a[i][j]<<" ";puts("");}

typedef pair<li, li> PI;


li a[200200];

li sum_odd[200200];
li sum_even[200200];

li dp[200200][3];

int main() {
    li n;
    cin >> n;
    rin{
        cin >> a[i];
    }
    sum_odd[0] = 0;
    sum_even[0] = 0;

    rin{
        sum_odd[i + 1] = sum_odd[i];
        sum_even[i + 1] = sum_even[i];
        if (i % 2 == 0) {
            sum_even[i + 1] += a[i];
        } else{
            sum_odd[i + 1] += a[i];
        }
    }

    if (n % 2 == 0) {
        li res = sum_odd[n];
        for (li i = 0; i < n; i += 2) {
            // どっかまでevenでとっててどっかからoddになる
            li even_sum = sum_even[i + 1];
            li odd_sum = (i + 3 < n ? sum_odd[n] - sum_odd[i + 3] : 0);
            res = max(res, even_sum + odd_sum);
        }
        cout << res << endl;
        return 0;
    }

    // dp[i][j] : i+1番目までで余裕がjあるときの合計の最大値
    rep(i, n + 1) {
        rep(j, 3) {
            dp[i][j] = -INF;
        }
    }
    dp[0][2] = 0;
    repp(i, 1, n + 1) {
        // dp[i][2]は偶数番目取ってく以外の選択肢なし
        dp[i][2] = dp[i - 1][2];
        if (i % 2 > 0 && i < n) {
            dp[i][2] += a[i - 1];
        }
        // dp[i][1]は今まで偶数番目まで取ってきてたんだけどそれを見逃すやつ
        dp[i][1] = dp[i - 1][1];
        if (i % 2 == 0) {
            dp[i][1] = max(dp[i - 2][2], dp[i - 1][1]) + a[i - 1];
        }
        // dp[i][0]はdp[i][1]が奇数番目を取ってるんだけど、それをさらに見逃すやつ
        // とdp[i][2]が偶数番目を取ってて一気に３つ飛ばすやつ
        dp[i][0] = dp[i - 1][0];
        if (i % 2 > 0) {
            dp[i][0] = max(dp[i][0], (i < 3 ? -INF : dp[i - 3][2]));
            dp[i][0] = max(dp[i][0], (i < 2 ? -INF : dp[i - 2][1]));
            dp[i][0] += a[i - 1];
        }
    }
    //rep(i, n + 1) {
    //    p5(i, (i > 0 ? a[i - 1] : 0ll), dp[i][0], dp[i][1], dp[i][2]);
    //}
    li res = -INF;
    rep(i, 3) {
        res = max(res, dp[n][i]);
    }
    cout << res << endl;


    return 0;
}