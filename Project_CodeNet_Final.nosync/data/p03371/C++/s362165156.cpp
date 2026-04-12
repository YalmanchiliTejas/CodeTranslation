#include <iostream>
#include <stdlib.h>
#include <vector> //vector
#include <algorithm> //sort()
#include <numeric>
#include <tuple>
#include <cmath>
#include <queue>

#define rep(i, n) for(int i=0; i<(int)(n);i++)
#define all(x) (x).begin(), (x).end()
#define debug(a) if(flagdebug){cout << "debug (" #a "):" << endl << (a) << endl;}

typedef uint64_t ulint;
typedef int64_t lint;

using namespace std;

template<class T> inline bool chmin(T& a, T b);
template<class T> inline bool chmax(T& a, T b);
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v);

template<class T> lint sum(vector<T> a);
template<class T> double ave(vector<T> a);

// struct pos
// {
//     lint x;
//     lint y;
//     lint dist;

// public:
//     pos(lint ax, lint ay, lint ad)
//     {
//         x = ax;
//         y = ay;
//         dist = ad;
//     }

//     bool operator<(const pos &another) const
//     {
//         return x < another.x;//年齢を比較
//     };
    
// };

lint a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;


bool flagdebug = false;


int main(){
//////////////////////////////////////////////////////

    //flagdebug = true; ///本番時削除！！！！！

    //入力

    lint a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    // vector<lint> s(n);
    // rep(i, n)
    // {
    //     cin >> s[i];
    // }

    //Cピザの最小枚数検討

    lint minp = min(x,y);
    lint an = 0;
    lint bn = 0;
    lint cn = 0;

    //Cが有用なケースは
    // 1. A + B より 2C の方が安い
    // 2. A または B より 2Cの方が安い

    if((a + b) * minp > 2 * c * minp) 
    {
        lint n = 2 * minp;
        cn += n;
        x -= n / 2;
        y -= n / 2;
    }

    debug(cn);

    if(x > 0 && a > 2 * c)
    {
        lint n = x * 2;
        cn += n;
        y -= n / 2;
        x = 0;
    }

    debug(an);
    debug(cn);

    if(y > 0 && b > 2 * c)
    {
        lint n = y * 2;
        cn += n;
        y = 0;
        x -= n / 2;
    }
    debug(an);
    debug(cn);

    if(x>0)an += x;
    if(y>0)bn += y;

    cout << an * a + bn * b + cn * c << endl;
    




    //2次元配列
    //vector<vector<lint>> mat(row, vector<lint>(column, 初期値));
    //ペア
    //pair<lint,lint> p = make_pair(1,2);
    //vector<pair<lint,lint>> c(100010, pair<lint,lint>(0,0));
    //タプル
    //tuple<lint,lint,lint> t  = make_tuple(1,2,3);


    //昇順ソート
    //sort(all(a));
    //降順ソート
    //sort(all(a),greater<lint>());
    //特殊なソート（ラムダ式）
    //sort(all(mat), [&i](const vector<lint> &a, const vector<lint> &b){return a[i] < b[i];});
    // //[&i]は参照する変数，いらなければからの大括弧でよし．
    
    //////////////////////////////////////////////////////
    //キュー
    //queue<lint> que;
    //que.push(value);
    //que.front(); //先頭を参照
    //que.top(); //トップを参照（消されないので消したい場合は直後にpop()を使う）
    //que.pop(); //追い出す
    //que.empty(); //空なら1，あれば0
    //優先度付きキュー
    //priority_queue<lint> que;
    //キューにque.push()で入れると最大値順に並べられる．que.pop()で取り出すときは常に最大値が前にくる．
    //最小値から取り出したい時はpriority_queue< lint, std::vector<lint>, std::greater<lint> >
    //////////////////////////////////////////////////////
    //スタック
    //stack<lint> stk;
    //stk.push(value);
    //stk.top(); //先頭を参照（消されないので消したい場合は直後にpop()を使う）
    //stk.pop(); //トップを削除
    //stk.empty(); //空なら1,あれば0
    //stk.size(); //数
    //


   

    // sort(input.begin() , input.end());

    // uint64_t max = numeric_limits<uint64_t>::max();


    //////////////////////////////////////////////////////
    // DP

//     // 無限大の値
//     const uint64_t INF = (uint64_t)1 << 60;
//     //const int64_t NINF = -1 * ((int64_t)1 << 60 );
 
//     // DP テーブル
//     uint64_t dp[100010];

//     //DPテーブル初期化（最小化用）
//     for (int i = 0; i < 100010; ++i)
//     {
//         //dp[i] = INF;
//         dp[i] = 0;
//     } 

//     // 初期条件
//     dp[0] = 0;

//     // ループ
//     for (int i = 1; i <= n; ++i) {
//         //chmin( dp[i], dp[i - 1] + abs( input[i] - input[i - 1] ));
//         //if (i < 2)continue;
//         //chmin( dp[i], dp[i - 2] + abs( input[i] - input[i - 2] ));



//         // chmax ( dp [i] , dp[i - 1]);
//         // chmax ( dp [i] , dp[i - 1] + input[i]);
//         // cout << "dp[" << i <<"] = " << dp[i] << endl;

//     }



// //////////////////////////////////////////////////////

//     cout << dp[n] << endl;

//////////////////////////////////////////////////////
// Ctrl + Opt + N to make
    return 0;
}


//最小化用関数
template<class T> inline bool chmin(T& a, T b)
{
    if (a > b) 
    {
        a = b;
        return true;
    }
    return false;
}

//最大化関数
template<class T> inline bool chmax(T& a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}


// vectorprint用
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
	int len = v.size();
	for (int i = 0; i < len; ++i) {
		s << v[i]; if (i < len - 1) s << "\t";
	}
	return s;
}

// //合計
// template<class T> lint sum(vector<T> a)
// {
//     return std::accumulate(a.begin(), a.end(), 0);
// }


// //平均
// template<class T> double ave(vector<T> a)
// {
//     return std::accumulate(a.begin(), a.end(), 0.0) / a.size();
// }


// 最大公約数
ulint gcd(lint a, lint b)
{
    if(b!=0)
    {
        gcd(b, a % b);
    }
    return a;    
}

ulint gcd(vector<lint> v)
{
    lint l = v.size();
    if(l>=2)
    {
        v[l-2] = gcd(v[l-2] , v[l-1]);
        v.pop_back();
    }
    if(l==1)return v[0];
    else
    {
        return 0;
    } 
}

//最小公倍数
ulint lcm(lint a, lint b)
{
    return a / gcd(a, b) * b;
}

ulint lcm(vector<lint> v)
{
    lint l = v.size();
    if(l>=2)
    {
        v[l-2] = lcm(v[l-2], v[l-1]);
        v.pop_back();
    }
    if(l==1)return v[0];
    else
    {
        return 0;
    }
}