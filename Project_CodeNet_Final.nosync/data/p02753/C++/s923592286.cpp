//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include<queue>
using namespace std;
//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}
//typedef
//------------------------------------------
typedef long long ll;
typedef long long LL;
typedef vector<long long > VLL;
typedef vector<long long > vll;
typedef pair<long long , long long> pll;
typedef pair<long long , long long> PLL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define VECMAX(x) *max_element(ALL(x))
#define VECMIN(x) *min_element(ALL(x))
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define MULTIPLE(i,n,k) for(int i = (k) ; i<(n) ; i+=k+1)//倍数ループ
//constant
//------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define SIZEOF(x) sizeof(x)/sizeof(x[0])

const long long INF = 100000000000000;
const long long NINF = -100000000000000;

//----------------search for specific figure--------------------
//--------------------------------------------------------------



ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll nCr(ll n, ll r) {

	if (n == 0) { return 0; }
	if (r == 0) { return 1; }
	if (r == 1) { return n; }
	if (n == r) { return 1; }

	if (r > n / 2) { r = n / 2; }

	ll result = 1;
	for (ll i = 1; i <= r; i++) {
		result *= (n - i + 1) / i;
    }
	return(result);
}


//firstが最大値（最小値） , second が index
pair<LL , LL> maxP(vll a , ll size){
    pair <ll , ll> p;
    vll::iterator iter = max_element(a.begin() , a.end());
    p.first = *iter;
    p.second = distance(a.begin() , iter);
    return p;
}

pair<LL , LL> minP(vll a , ll size){
    pair <ll , ll> p;
    vll::iterator iter = min_element(a.begin() , a.end());
    p.first = *iter;
    p.second = distance(a.begin() , iter);
    return p;
}

ll sumL(vll a , ll size){
    ll sum = 0;
    REP(i,size){
        sum += a[i];

    }
    return sum;
}

 //aのなかにtがいくつあるか
ll counT(VLL a , ll t ){
   
    sort(a.begin(),a.end());
    return upper_bound(a.begin(),a.end(),t)-lower_bound(a.begin() , a.end() , t);
}

#define COUNT(a,b) counT((a),(b))
#define MAX(x) maxP(x,x.size())
#define MIN(x) minP(x,x.size())
#define SUM(x) sumL(x,x.size())

//-------------------DIVIDE----------------------
// DIV[i][j] は　i の j分割数 j == 0 && i != 0 なら 0  
//並び順を区別しない

ll DIV[1000+1][1000+1];
void divide(ll n ,ll m){
    DIV[0][0]= 1;
    FOR(i,1,n+1){
        DIV[i][0] = 0;
    }
    REP(i,n+1){
        DIV[i][1] = 1;
    }
    FOR(i,1,m+1){
        FOR(t,0,n+1){
            if(DIV[t][i] > 0)continue;
            if(t>=i){
                DIV[t][i]=DIV[t-i][i] + DIV[t][i-1];
            }else{
                DIV[t][i] = DIV[t][i-1];
            }
        }
    }
}
#define DIVIDE(a,b) (DIV[a][b] - DIV[a][(b)-1])


//-------要素を見つける-----------


ll search(vll &a , ll n ){//a内のnのindexを返す
    std::vector<ll>::iterator iter = std::find(a.begin(), a.end(), n);
    size_t index = distance(a.begin(), iter);
    return index;
}



//------------素数判定-----------------


//------------素数判定-----------------
vector<bool> IS_PRIME_CONTAINER(1000005 , true);
//メモリを圧迫する可能性あり

void IsPrime_Contain(ll num){
    IS_PRIME_CONTAINER[0] = false;
    IS_PRIME_CONTAINER[1] = false;
    FOR(i,2,sqrt(num)+1){
        if(IS_PRIME_CONTAINER[i]){
            FOR(j,2,num/i + 1){
                if(j*i<=num){
                    IS_PRIME_CONTAINER[i*j]=false;
                }
            }
        }
    }
}

inline bool IsPrime(ll num){
    return IS_PRIME_CONTAINER[num];
}



//---------ベルマンフォード----------
struct E{
    ll from , to, cost;
};
ll DIST[100005];
//start と 辺の数 m 辺の情報 x を入力
void shortest(LL s , vector<E> &x , ll m){
    REP(i,100000){
        DIST[i] = INF;
    }
    DIST[s] = 0;
    while(1){
        bool t = false;
        REP(i,m){
            E h = x[i];
            if(DIST[h.from] != INF && DIST[h.to] > DIST[h.from] + h.cost){
                DIST[h.to] = DIST[h.from] + h.cost; 
                t = true;
            }
        }
        if(!t){
            break;
        }
    }
}










//----UnionFind-----

class UnionFind{
    public:
    vll par;
    vll rank;//rankが高いほど上の親である
    UnionFind(LL N):par(N),rank(N){
        REP(i,N)par[i] = i;
        REP(i,N)rank[i] = 0;
    }
    ~UnionFind(){}
    LL root(LL x){
        if(par[x] ==x)return x;
        else {
            par[x] = root(par[x]);
            return par[x];
        }
    }
    void unite(LL x, LL y){
        LL rx = root(x);
        LL ry = root(y);
        if(rx == ry)return;
        if(rank[rx] < rank[ry]){
            par[rx] = ry;//rankの高い方を親にする
        }else{
            par[ry] = rx;
            if(rank[rx] == rank[ry]){
                //rankがどちらも同じ時、どちらか好きな方を親にしてそのrankを1上げる
                rank[rx]++;
            }
        }
        
    }
    bool same(LL x, LL y){
        LL rx = root(x);
        LL ry = root(y);
        return rx == ry;
    }
};


//--------BFS---------


class BFS_shortestDistance{
    public:
    BFS_shortestDistance(vector<vector <char> > p_ , ll h_ , ll w_){
        p = p_;
        h=h_;
        w=w_;
        initial_number = h*w*2;
        REP(i,h){
            vector <LL> k(w);
            REP(t,w)k[t] =  initial_number;
            field.push_back(k);
        }
    }
    vector<vector <char> > p;

    ll h;
    ll w;
    ll initial_number;//初期化用数値

    vector< vector<LL> >field;  //この変数に書き込む


    pair<LL , LL > plus(pair<LL , LL> &a, pair<LL , LL > &b){
        pair<LL , LL> p;
        p.first = a.first + b.first;
        p.second = a.second + b.second;
        return p;
    }
    bool equal(pair<LL , LL> &a, pair<LL , LL > &b){
        return (a.first == b.first && a.second == b.second);
    }
    bool is_in_field(int h, int w, const pair<LL , LL> &point)
    {
        const int c = point.second;
        const int r = point.first;
        return (0 <= c && c < w) && (0 <= r && r < h); 
    }

    // fieldの中身を初期化
    //最短距離がh*w*2になることはないのでこれで初期化する
    void init(){
        REP(i,field.size()){
            REP(t,field[i].size()){
                field[i][t] = initial_number;
            }
        }
    }

    // sy , sx はスタート位置の 『INDEX』!! 
    // syが縦　sx が横
    void shortest(ll sy,ll sx){
        //初期化
        init();

        pair <LL , LL> c[4];
        c[0].first = 0;
        c[0].second = 1;
        c[1].first = 0;
        c[1].second = -1;
        c[2].first = 1;
        c[2].second = 0;
        c[3].first = -1;
        c[3].second = 0;
        queue <pair<LL ,LL> >Q;
        pair<LL , LL> s;
        s.first = sy;
        s.second = sx;
        field[sy][sx] = 0;//スタート位置のみ0で初期化
        
        Q.push(s);
        while(Q.empty() == false){
            pair <LL , LL> now = Q.front();
            Q.pop();        

            for(int u = 0; u < 4 ; u++){
                pair<LL , LL > x = c[u];
                pair<LL , LL> next = plus(now , x);
                if(is_in_field(h,w,next)){
                    if(p[next.first][next.second] == '.'){
                        //まだ到達してない　＝＝　field の値が initial_number　
                        if(field[next.first][next.second] == initial_number){
                            field[next.first][next.second] = field[now.first][now.second] + 1;
                            Q.push(next);
                        }else{
                            //すでに到達済みである＝＝これ以前にQueueから出てきたpairがすでに
                            //到達している＝＝すでにfieldの値が最小値であることは明らか;
                        }
                    }
                }
            }
        }
    }


};



//-----------DP---------------//


// b < a => true , a = b;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
// b > a => true , a = b;
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}







//-----------MODつきCombination------------//
const int MAX = 1000007;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}




//-------------bit全探索---------------


//aは空の二重配列
//aに格納する
void BIT(vector<vll> &a , ll n){
    for(ll bit = 0; bit < (1<<n) ; bit++){
        vll P;
        a.push_back(P);
        for(ll i = 0 ; i < n ; i++){
            if(bit & (1<<i)){
                a[bit].push_back(i);
            }
        }
    }
}





//桁数

int getdigit(ll n){
    return log10(n)+1;
}

ll keta(ll n , ll k){
    if(k > getdigit(n)){
        return -1;
    }else if(k==1){
        return n%10;
    }else{
        ll p = 1;
        REP(i,k)p*=10;
        return (n%p)/(p/10); 
    }
}



//-----------MAIN------------//






int main(){
    string s;
    cin>> s;
    map<char , ll>p;
    REP(i,s.size()){
        p[s[i]]++;
    }

    if(p['A']&&p['B']){
        cout << "Yes" << endl;

    }else{
        cout << "No"<<endl;
    }
return 0;
}