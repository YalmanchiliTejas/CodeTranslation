#include <bits/stdc++.h>
using intl = long long;
using itnl = long long;//typo用
using itn = int;//typo用
using ld = long double;
using namespace std;
#define rep(i, n) for(intl i = 0; i < (intl)(n); i++)
#define rrep(i, n) for(intl i = (intl)(n) - 1; i >= 0; i--)
#define repi(i, a, b) for(intl i = (intl)(a); i < (intl)(b); i++)
#define rrepi(i, a, b) for(intl i = (intl)(a); i > (intl)(b); i--)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,1,sizeof(x))
#define fill(x,y) memset(x,y,sizeof(x))
#define alength(a) (sizeof(a) / sizeof(a[0]))
#define debug(x) cout << #x << ":" << x << endl
#define rdebug(i,x) rep(i, alength(x))cout << #x << "[" << i << "]:" << x[i] << endl//1次元配列の出力
#define rrdebug(i, j, x) rep(i, alength(x))rep(j, alength(x[i]))cout << #x << "[" << i << "][" << j << "]:" << x[i][j] << endl//二次元配列の出力
#define pb push_back
#define mp make_pair
#define pii pair<intl,intl>
const intl INF = 1e9;
const intl MOD = 1e9+7;
const ld EPS = 1.0e-14;//-9
const ld PI = acos(-1);
void fp(bool f){cout << (f ? "Yes" : "No") << endl;}
void fp(bool f, string s, string t){cout << (f ? s : t) << endl;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) {a = b; return true;} return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) {a = b; return true;} return false; }
intl gcd(intl a, intl b){ if(!b)return a; return gcd(b, a % b); }
intl lcm(intl a,intl b){ return a / gcd(a, b) * b; }
intl kai(intl k){//k!を求める関数,
    intl a = 1;
    for(int i = 2; i <= k; i++){
        a *= i;
    }
    return a;
}
intl digit10(intl a){//aを10進数で表したときの桁数を求める関数
    intl b = 0;
    do{
        a /= 10;
        b++;
    }while(a);
    return b;
}


signed main(){
    cout << fixed << setprecision(10);
    intl h,w;
    cin >> h >> w;
    char a[10][10];
    rep(i,10)rep(j,10)a[i][j] = '.';
    repi(i,1,h+1)repi(j,1,w+1)cin >> a[i][j];
    bool f = false;
    bool flag[h+2][w+2];
    m0(flag);
    queue<pii > q;
    q.push(mp(1,1));
    flag[1][1] = true;
    vector<pii > move = {{0,1},{1,0}};
    while(!q.empty()){
        pii p = q.front();
        q.pop();
        if((a[p.first + 1][p.second] == '#')&&(a[p.first][p.second +1] == '#')){
            break;
        }
        for(auto i: move){
            intl fi = p.first + i.first;
            intl se = p.second + i.second;
            if(flag[fi][se])continue;
            if(a[fi][se] == '#'){
                flag[fi][se] = true;
                q.push(mp(fi,se));
            }
            if((fi == h)&&(se == w)){
                f = true;
                break;
            }
        }
        if(f)break;
    }
    bool ans = f;
    if(ans){
        repi(i,1,h+1){
            repi(j,1,w+1){
                //cout << flag[i][j] << " ";
                if((!(flag[i][j]))&&(a[i][j] == '#'))ans = false;
            }
            //cout << endl;
        }
    }
    fp(ans,"Possible","Impossible");
    return 0;
}