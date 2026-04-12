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
inline long long toint(string s) {long long v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}
//typedef
//------------------------------------------
typedef long long ll;
typedef long long LL;
typedef vector<int > vi;
typedef vector<long long > VLL;
typedef vector<long long > vll;
typedef vector<string > ves;
typedef vector<char > vech;

typedef pair<long long , long long> pll;
typedef pair<long long , long long> PLL;
typedef map<ll , ll >mll;
typedef map<int , int >mii;
typedef map<char , int >mci;
typedef map<char , ll >mcl;


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
//#define MULTIPLE(i,n,k) for(int i = (k) ; i<(n) ; i+=k+1)//倍数ループ
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

#define CIN(a) REP(i,a.size())cin >> a[i];


//-------------------------------------------------------------




ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
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
#define DIVIDE(a,b) (DIV[a][b] - DIV[a][(b)-1]) //DIV[a-b][b]と同じ


//-------要素を見つける-----------


ll search(vll &a , ll n ){//a内のnのindexを返す
    std::vector<ll>::iterator iter = std::find(a.begin(), a.end(), n);
    size_t index = distance(a.begin(), iter);
    return index;
}



//------------素数判定-----------------


//------------素数判定-----------------
class Judge{
    public:
    vector<bool> IS_PRIME_CONTAINER;
    Judge(int max_):IS_PRIME_CONTAINER(max_, true){
        max = max_;
    }
    int max;//この値-1まで素数判定する
    //メモリを圧迫する可能性あり
    void IsPrime_init(){
        IS_PRIME_CONTAINER[0] = false;
        IS_PRIME_CONTAINER[1] = false;
        FOR(i,2,sqrt(max)+1){
            if(IS_PRIME_CONTAINER[i]){
                FOR(j,2,(max)/i + 1){
                    if(j*i<=max){
                        IS_PRIME_CONTAINER[i*j]=false;
                    }
                }
            }
        }
    }

    inline bool IsPrime(ll num){
        return IS_PRIME_CONTAINER[num];
    }


};


//---------ベルマンフォード----------

    //頂点の値はindexとする
class Bellman{
    public:
    vll DIST;
    //max は　頂点の数
    
    Bellman(int max_ ):DIST(max_ , INF){
        max = max_;
        
    }
    ~Bellman(){
         std::vector<ll>().swap(DIST);
    }
    int max;
    //int m;//辺の数
    struct E{
        //classの外で構造体Eを宣言するときは Bellman::E と宣言する
        // from から toは一方通行であることに注意
        ll from , to, cost;
    };
    //はじめに必ず初期化
    void init(){
        REP(i,max){
                DIST[i] = INF;
        }
    }
    
    
    //startはindex(0から)
    //start と 辺の数 m 辺の情報 x を入力

    //頂点a,bが両方向に繋がってるなら、
    //vector<Bellman::E>には(a,b,c)と(b,a,c)の両方を入れないといけない
    void shortest(LL s , vector<E> &x ){
        REP(i,100000){
            DIST[i] = INF;
        }
        DIST[s] = 0;
        while(1){
            bool t = false;
            REP(i,x.size()){
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
    
    

};



//----------ダイクストラ------------
class dijkstra{
    //頂点の値はindexとする
    public:
    int V;//Vは頂点の個数
    struct edge {
    int to;
    int cost;
    };

    




    public:
    // G[i]には頂点iから出る辺の情報が入ってる

    vll dist;//最短距離をまとめたvector

    //全ての辺からの距離を求めたい場合は、
    //
    /*
        vector<vector<int> >vecを用意
           ↓  ↓　↓
        REP(i,V_){
            DIJKSTRA.shortest(i);
            vec.push_back(DIJKSTRA.dist);
        }
        DIJKSTRA.init();


        これはO(N*N*log2(N))
    */



    vector<vector<edge> > G;
     //頂点a,bが両方向に繋がってるなら、
    //Gには(a,b)と(b,a)の場合の両方を入れないといけない

    /*
        REP(i ,G.size()){
            while(頂点iに繋がってる辺の個数){
                G[i].push_back(辺の情報edge);
            }
        }
    
    */
    dijkstra(ll V_ ):G(V_*V_){
        REP(i,V_){
            dist.push_back(INF);
        }
        V=V_;
    }
    ~dijkstra(){
        std::vector<ll>().swap(dist);
        vector<std::vector<edge> >().swap(G);
    }
    void init(){
        REP(i,dist.size())dist[i] = INF;
    }


    void shortest(int s) {
        priority_queue<pll, vector<pll>, greater<pll> > que;
        
        dist[s] = 0;
        que.push(pll(0, s));

        while (!que.empty()) {
            pll p = que.top();
            que.pop();
            int v = p.second;
            if (dist[v] < p.first) continue;

            for (int i=0; i<G[v].size(); ++i) {
                edge e = G[v][i];
                if (dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    que.push(pll(dist[e.to], e.to));
                }
            }
        }
    }
};




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
        if(par[x] ==x)return x;//ここが親
        else {
            par[x] = root(par[x]);//親を再起的に見つける
            return par[x];
        }
    }
    void unite(LL x, LL y){
        LL rx = root(x);
        LL ry = root(y);
        if(rx == ry)return;
        if(rank[rx] < rank[ry]){
            //親をくっつけて同じグループにする
            par[rx] = ry;//rankの高い方を親にする(この場合、rxの親がry)
        }else{
            par[ry] = rx;//ryの親をrxにした
            if(rank[rx] == rank[ry]){
                //rankがどちらも同じ時、親にした方のrankを1上げる
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


class BFS{
    public:
    BFS(vector<vector <char> > field_ , ll h_ , ll w_){
        field = field_;
        h=h_;
        w=w_;
        initial_number = INF;
        REP(i,h){
            dist.push_back(vector <LL> (w , initial_number));
        }
    }

    ~BFS(){
        std::vector<std::vector<ll> >().swap(dist);
        std::vector<std::vector<char> >().swap(field);
    }
    vector<vector <char> > field;

    ll h;
    ll w;
    ll initial_number;//初期化用数値

    vector< vector<LL> >dist;  //この変数に書き込む


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
        REP(i,dist.size()){
            REP(t,dist[i].size()){
                dist[i][t] = initial_number;
            }
        }
    }

    // sy , sx はスタート位置の 『INDEX』!! 
    // syが縦　sx が横
    // .を道、#を障害物とする
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
        dist[sy][sx] = 0;//スタート位置のみ0で初期化
        
        Q.push(s);
        while(Q.empty() == false){
            pair <LL , LL> now = Q.front();
            Q.pop();        

            for(int u = 0; u < 4 ; u++){
                pair<LL , LL > x = c[u];
                pair<LL , LL> next = plus(now , x);
                if(is_in_field(h,w,next)){
                    if(field[next.first][next.second] == '.'){
                        //まだ到達してない　＝＝　distの値が initial_number　
                        if(dist[next.first][next.second] == initial_number){
                            dist[next.first][next.second] = dist[now.first][now.second] + 1;
                            Q.push(next);
                        }else{
                            //すでに到達済みである＝＝これ以前にQueueから出てきたpairがすでに
                            //到達している＝＝すでにdistの値が最小値である;
                        }
                    }
                }
            }
        }
    }


};



//-----------動的計画法---------------//


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






//-----------２つの順番を考慮しないintをもつ型-------------
//   unorder <typename> instance(para , para2);
template<class T>
class unorder {
    
    public: 
    T a , b;

    unorder(T a_ , T b_){
        (a = a_);
        (b = b_);
    }
    ~unorder(){

    }
    public:
   
    bool operator  == (unorder y){
        return (this->a + this->b == y.a + y.b && this->a*this->b == y.a*y.b);
    }
    bool operator  != (unorder y){
        return (this->a + this->b != y.a + y.b || this->a*this->b != y.a*y.b);
    }

    void operator = (pair<T , T> p){
        this->a = p.first;
        this->b = p.second;
    }

};








//-------素因数分解---------------



vector<pair<ll , ll > > PrimeFactors(ll n)
{

    std::map<ll,ll> out;
    vector<pair<ll , ll > > answer;
	while (n % 2 == 0)
	{
		++out[2];
		n = n / 2;
	}
    if(out[2])answer.push_back(make_pair(2 , out[2]));

	for (ll i = 3; i <= sqrt(n); i = i + 2)
	{
		while (n%i == 0)
		{
			++out[i];
			n = n / i;
		}

        if(out[i])answer.push_back(make_pair(i , out[i]));
	}

	if (n > 2)
		++out[n];
    if(out[n])answer.push_back(make_pair(n , out[n]));

    return answer;
}



void  StringSort(vector<string> &S){
    map<int , int> SwapInd;
    int maxi = 0;//Sに含まれる文字列の最大文字列長
    for(int i = 0 ; i < S.size() ; i++){
        if(S[i].size() > maxi) maxi = S[i].size();
    }

    for(int i = 0 ; i < maxi ; i++){//ここが右端の文字から左の文字へのループ
        int k = maxi - i;//今考えている文字が左から何文字目かを表す(indexではないので-1することに注意)
        int sort_num = 0;//文字列長がk+1以上ある要素の個数
                        //ソートしたい文字列の個数と言い換えられる

        for(int j = 0 ; j < S.size() ; j++){
            if(S[j].size() >= k){//S[j]にk+1文字目が存在すればSwapInd[j]に記録
                SwapInd[j]=1;
                sort_num++;//インクリメント
            }
        }

        int swapped = 0;//Sの右側グループの左端indexを0としたきのindex
        //ここからグループ分けをします
        for(int j = 0 ; j< S.size() ; j++){
            //ここで、S.size() - sort_num は右側と左側の境界である
            if(SwapInd[j] == 1 && j < S.size() - sort_num){
                
                //j番目の文字列がソート対象（文字列長k以上）
                //かつ、S[j]が右側グループに入っていない
                if(SwapInd[S.size() - sort_num + swapped] == 0){
                    //右側グループの左からswapped番目の文字列がソート対象でない場合
                    iter_swap(S.begin() + j , S.begin() + S.size() - sort_num + swapped);
                    //入れ替える
                }else{
                    //右側グループの左からswapped番目の文字列がソート対象である場合
                    //右側グループの左からswapped番目の文字列がソート対象でなくなるまで
                    //swappedをインクリメントする
                    while(SwapInd[S.size() - sort_num + swapped] != 0){
                        swapped++;
                        if(S.size() - sort_num + swapped >= S.size()){
                            break;//out of index
                        }
                        if(S.size() - sort_num + swapped < S.size()){
                            iter_swap(S.begin() + j , S.begin() + S.size() - sort_num + swapped);
                        }
                    }
                   
                }
                SwapInd[j] = 0;//更新
                SwapInd[S.size() - sort_num + swapped] = 0;//更新
                swapped++;//左右境界から何番目に要素を追加するかを表す



            }//Sのグループ分け完了
            

           




        }

        vector<string> WhatSorted(sort_num);
        vector<pair<int , int> > char_and_index(sort_num);
        //sortする文字とそのindex,

        for(int j = 0 ; j < sort_num ; j++){
            if(S[S.size() - sort_num + j][k-1] >= 65 &&S[S.size() - sort_num + j][k-1] <=90){
                char_and_index[j].first = (int)S[S.size() - sort_num + j][k-1] + 32;
            }else{
                char_and_index[j].first = (int)S[S.size() - sort_num + j][k-1];
            }
            char_and_index[j].second = j;
            WhatSorted[j] = S[S.size() - sort_num + j];//境界からj番目の文字列
        }
        sort(char_and_index.begin() , char_and_index.end());

        for(int j = 0 ; j < sort_num ; j++){
            S[S.size() - sort_num + j] = WhatSorted[char_and_index[j].second];
        }

    }
}






//-----------MODつきCombination------------//
class ModComb{
    public:
    vll fac ;
    vll finv ;
    vll inv ;
    ModComb(ll MAX_ , ll MOD_):fac(MAX_),finv(MAX_),inv(MAX_){
        MAX = MAX_;
        MOD = MOD_;
        }
    ~ModComb(){
        std::vector<ll>().swap(fac);
        std::vector<ll>().swap(finv);
        std::vector<ll>().swap(inv);
    }
    int MAX;
    int MOD;
    

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

};




//-------------bit全探索---------------


//aは空の二重配列
//aに格納する
//a[i]には小さい方からi個目のn桁のbinaryで1が現れる桁の情報が入っている
//a[i][j]はa[i]のbitが1になる桁を表す。
//a[i]の値はpow(2,0)<=pow(2,k)<=pow(2,n-1)となるkが昇順で入っている
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


ll kiriage(ll a , ll b){
    return a/b+(a%b==0);
}




template<class T>//Tはvector or string
pair<vector<ll> , T >seqence(T x){  //xの連続してる部分をvectorにまとめる
    // firstが連続する個数、secondが値
    pair<vll , T> s;
    bool flag = 0;//今連続しているかどうか
    ll now;
    ll seq = 1;
    ll next;
    REP(i,x.size()){
        if(i+1 >= x.size()){//次の数が範囲外になるとき
            now = x[i];
            s.first.push_back(seq);
            s.second.push_back(now);
            break;
        }else{
            now = x[i];
            next = x[i+1];
            if(flag){
                if(now == next){
                    seq++;
                }else{
                    s.first.push_back(seq);
                    s.second.push_back(now);
                    seq = 1;
                    flag = 0;
                }
            }else{
                if(now == next){
                    seq++;
                     flag = 1;
                }else{
                    s.first.push_back(seq);
                    s.second.push_back(now);
                    seq = 1;  
                }
            }
        }
    }
    
    return s;
}




//パスカルの三角形
vector<vector<ll> > pascal(66);//65段までならいける
vll getpascal(ll n){
    if(pascal[n].size()>0)return pascal[n];
    vll e;
    if(n == 0){
        e.push_back(1);
    }else{
        e.push_back(1);
        vll ajj = getpascal(n-1);
        REP(i , ajj.size()-1){
            e.push_back(ajj[i]+ajj[i+1]);
        }
        e.push_back(1);
    }
    return pascal[n] = e;
}







void pascal_calc(ll n){
    pascal[n] = getpascal(n); 
}

//すぐにオーバーフローするから使わない方がいいシグマ計算
vector<vector<long long > > Sigma(11,vll(1000005));
//sigma(a,n) := (k^a)の和(0->n) 
long long sigmaCalc(ll a , ll n){
    if(Sigma[a][n] != 0){
        return Sigma[a][n];
    }
    pascal_calc(a+1);
    ll ans = 0;
    if(a == 0){
        ans = n;
    }else{
        ll coefficient = pascal[a+1][1];
        ans += pow(n+1 , a+1)-1;
        REP(i,a){
            ans-=sigmaCalc(a-1-i,n)*pascal[a+1][2+i];
        }
        ans/=coefficient;
    }
    return Sigma[a][n] = ans;
}















//-----------MAIN------------//
//注意::::DPの配列、vectorはグローバル変数を使え！！そして引数として与えるな！！
//       Sqrは２乗 sqrtはルート
//　　　　




int main(){
    LL n , m , k , A , B;    string s;    map<ll , ll>p;
    vector<pll> Pairs;pll Ap;
    
    cin >> n;
    if(n>=30){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}





