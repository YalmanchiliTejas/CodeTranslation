#include <bits/stdc++.h>

#define rep0(i, n) for(int i=0; i<(int)(n);i++)
#define rep1(i, n) for(int i=1; i<=(int)(n);i++)
#define all(x) (x).begin(), (x).end()
#define debug(a) if(flagdebug){cout << "debug (" #a "):" << endl << (a) << endl;}

using namespace std;

typedef uint64_t ulint;
typedef int64_t lint;

// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;

template<class T> lint sum(vector<T> a);
template<class T> double ave(vector<T> a);
template<typename T> ostream& operator << (ostream& s, const vector<T>& v);
ulint gcd(lint a, lint b);
ulint lcm(lint a, lint b);

bool flagdebug = false;





int main(){
//////////////////////////////////////////////////////

    flagdebug = true; ///本番時削除！！！！！

    //入力

    lint n;
    cin >> n;

    vector<lint> a(n);
    //2次元配列
    //vector<vector<lint>> mat(row, vector<lint>(column, 初期値));

    rep0(i, n)
    {
        cin >> a[i];
    }

    multiset<lint> colmin; //別々の色ごとで最後に塗られた数
    //vector<lint> col;

    colmin.insert(a[n-1]);

    for(lint i = n - 2 ; i >= 0 ; i --)
    {
        auto it = colmin.upper_bound(a[i]);
        if(it == colmin.end())//発見できなかったので新色を作る
        {
            colmin.insert(a[i]);
        }
        else
        { //既存の色で塗る
            colmin.erase(it);
            colmin.insert(a[i]);
        }
        
    }

    cout << colmin.size() << endl;

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
    //ソート済集合（順序付き集合）
    //set<lint> st;
    //itr.insert(0);
    //auto itrmin = st.begin(); //最小値の次へアクセス
    //auto itrmax = st.end(); //最大値の次へアクセス（かならずデクリメントが必要）
    //itrmax --; //最大値はst.end()の1つ前
    //st.erase(0);
    //st.find;
    
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
// Ctrl + Opt + N to make
    return 0;
}

//vectorprint用
template<typename T> ostream& operator << (ostream& s, const vector<T>& v) {
    s << "[\t";
    for (auto i = v.begin(); i < v.end() - 1; i++){s << *i << "\t";}
    s << *(v.end() - 1) << "\t]\n";
	return s;
}

// 最大公約数
ulint gcd(lint a, lint b){
    if(b!=0){return gcd(b, a % b);}
    return a;    
}

//最小公倍数
ulint lcm(lint a, lint b){
    return a / gcd(a, b) * b;
}
