/*
          , -- 、
        /;;;;;;', 　　　
        i二二二i
      , ' 　    ヽ ???
     i　ﾉﾉﾉﾉﾉﾍ .', 　　
     〉ﾘi' ﾟ ヮﾟﾉﾚく　 WAyon..........
  ○⊂}〈lﾄ--ｲl〉{つ● 　　
      ,ｒ/ー i-ヽヽ 　　　
     ｀｀i_ﾗi_ﾗ
*/

#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
const int INF=(int)1e12;
const int mod=(int)1e9+7;
#define all(a) (a).begin(),(a).end()
typedef vector<vector<int>> graph;

#define pb push_back

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int gcd(int a,int b){
    if(a%b==0)return b;
    return gcd(b,a%b);
}

int digit[10010],dp[10010][110][2];
signed main() {
    string s;int d;cin >>s>>d;int n=s.size();
    rep(i,s.size()){
        digit[i]=(s[i]-'0');
    }
    memset(dp,0LL,sizeof(dp));


    rep(i,10){
        if(i<digit[0])dp[0][i%d][0]+=1;
        else if(i==digit[0])dp[0][i%d][1]+=1;
    }

    rep(i,n-1){
        rep(j,d){
                rep(k, 2) {
                    rep(nn,10) {
                        if (k == 1) {
                            if (nn < digit[i+1]) {
                                dp[i + 1][(j + nn) % d][0] += dp[i][j][1] % mod;
                                dp[i + 1][(j + nn ) % d][0] %= mod;
                            } else if (nn == digit[i+1]) {
                                dp[i + 1][(j + nn)%d][1] += dp[i][j][1] % mod;
                                dp[i + 1][(j + nn ) % d][1] %= mod;
                            }
                        }
                        else {
                            dp[i + 1][(j + nn) % d][0] += dp[i][j][0] % mod;
                            dp[i + 1][(j + nn) % d][0] %= mod;
                        }
                    }
                    }
                }

        }



    int ans=(dp[n-1][0][1]+dp[n-1][0][0]+1000000006)%mod;
    cout <<ans<<endl;
}















