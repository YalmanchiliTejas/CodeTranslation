#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>

#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define bit(n,k) (((ll)n>>(ll)k)&1) /*nのk bit目*/
#define pb push_back
#define eb emplace_back
#define SZ(x) ((ll)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
const long long INF= 1e+18+1;
//long long INF=(1LL<<31)-1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
typedef struct Point_Coordinates {
    ll x, y;
} point;
const ll MOD=1000000007LL;
//ll MOD=1000000007LL;
//const ll MOD=998244353LL;
//const ll MOD=1777777777LL;
//const ll MAX_V=114514LL;
//const ll MAX = 500010LL;
const ll mod=MOD;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vl dx={0,0,1,-1};
vl dy={1,-1,0,0};

//素因数分解O(√n)
map<ll,ll>prime_factor(ll n){
  map<ll,ll>res;
  for(ll i=2;i*i<=n;i++){
    while(n%i==0){
      res[i]++;
      n/=i;
    }
  }
  if(n!=1)res[n]=1;
  return res;
}

const ll MAX = 2000010;
long long fac[MAX], finv[MAX], inv[MAX];
//finvが階乗の逆元

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll modpow(ll a, ll n, ll mod) {
  
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
/*ll N=2000010;
vl arr(N);
void Eratosthenes(){
	for(ll i = 0; i < N; i++){
		arr[i] = 1;
	}
        arr[1]=0;
	for(ll i = 2; i < sqrt(N); i++){
		if(arr[i]){
			for(ll j = 0; i * (j + 2) < N; j++){
				arr[i *(j + 2)] = 0;
			}
		}
	}
}*/
//素数判定O(√n)
bool is_prime(ll n){
  for(ll i=2;i*i<=n;i++){
    if(n%i==0)return false;
  }
  return n!=1;
}

//約数の列挙O(√n)
vector<ll>divisor(ll n){
  vector<ll>res;
  for(ll i=1;i*i<=n;i++){
    if(n%i==0){
      res.push_back(i);
      if(i != n/i) res.push_back(n/i);
    }
  }
  return res;
}

/* SegTree<X>(n,fx,ex): モノイド(集合X, 二項演算fx, 単位元ex)についてサイズnで構築
    set(int i, X x), build(): i番目の要素をxにセット。まとめてセグ木を構築する。O(n)
    update(i,x): i 番目の要素を x に更新。O(log(n))
    query(a,b):  [a,b) 全てにfxを作用させた値を取得。O(log(n))
*/
template <typename X>
struct SegTree {
    using FX = function<X(X, X)>;
    int n;
    FX fx;
    const X ex;
    vector<X> dat;
    SegTree(int n_, FX fx_, X ex_) : n(), fx(fx_), ex(ex_), dat(n_ * 4, ex_) {
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }

    void set(int i, X x) { dat[i + n - 1] = x; }
    void build() {
        for (int k = n - 2; k >= 0; k--) dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
    }

    void update(int i, X x) {
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;  // parent
            dat[i] = fx(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }

    // the minimum element of [a,b)
    X query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    X query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return ex;
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return fx(vl, vr);
        }
    }
    /* debug */
    inline X operator[](int a) { return query(a, a + 1); }
    void print() {
        for (int i = 0; i < 2 * n - 1; ++i) {
            cout << (*this)[i];
            if (i != n) cout << ",";
        }
        cout << endl;
    }
    /*
    使用例
    auto fx=[](int x1,int x2)->int{return max(x1,x2);};
    ll ex=0;
    SegTree<ll>rmq(n,fx,ex);*/
};

/* Trie 木： 文字の種類(char_size)、int型で0に対応する文字(base)
    insert(word): 単語 word を Trie 木に挿入する
    search(word): 単語 word が Trie 木にあるか判定する
    start_with(prefix):  prefix が一致する単語が Trie 木にあるか判定する
    count(): 挿入した単語の数を返す
    size(): Trie 木の頂点数を返す
    計算量：insert, search ともに O(M)（Mは単語の長さ）
*/
template <int char_size, int base>
struct Trie {
    struct Node {            // 頂点を表す構造体
        vector<int> next;    // 子の頂点番号を格納。存在しなければ-1
        vector<int> accept;  // 末端がこの頂点になる単語の word_id を保存
        int c;               // base からの間隔をint型で表現したもの
        int common;          // いくつの単語がこの頂点を共有しているか
        Node(int c_) : c(c_), common(0) {
            next.assign(char_size, -1);
        }
    };
    vector<Node> nodes;  // trie 木本体
    int root;
    Trie() : root(0) {
        nodes.push_back(Node(root));
    }
    // 単語の挿入
    void insert(const string &word, int word_id) {
        int node_id = 0;
        for (int i = 0; i < (int)word.size(); i++) {
            int c = (int)(word[i] - base);
            int &next_id = nodes[node_id].next[c];
            if (next_id == -1) {  // 次の頂点が存在しなければ追加
                next_id = (int)nodes.size();
                nodes.push_back(Node(c));
            }
            ++nodes[node_id].common;
            node_id = next_id;
        }
        ++nodes[node_id].common;
        nodes[node_id].accept.push_back(word_id);
    }
    void insert(const string &word) {
        insert(word, nodes[0].common);
    }
    // 単語とprefixの検索
    bool search(const string &word, bool prefix = false) {
        int node_id = 0;
        for (int i = 0; i < (int)word.size(); i++) {
            int c = (int)(word[i] - base);
            int &next_id = nodes[node_id].next[c];
            if (next_id == -1) {  // 次の頂点が存在しなければ終了
                return false;
            }
            node_id = next_id;
        }
        return (prefix) ? true : nodes[node_id].accept.size() > 0;
    }
    // prefix を持つ単語が存在するかの検索
    bool start_with(const string &prefix) {
        return search(prefix, true);
    }
    // 挿入した単語の数
    int count() const {
        return (nodes[0].common);
    }
    // Trie木のノード数
    int size() const {
        return ((int)nodes.size());
    }
};

ll dfs(vvl & data, ll n){
    ll res=0;
    if(data[n].size()==0)return 1;
    ll res_max=0;
    ll res_min=INF;
    rep(i,data[n].size()){
      res_max=max(res_max,dfs(data,data[n][i]));
      res_min=min(res_min,dfs(data,data[n][i]));
    }
    return res_max+res_min+1;
}

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cout << fixed << setprecision(10);
  /*--------------------------------*/
  
  /*Trie<26,'a'>trie;
  ll n;cin>>n;
  vl s(n);
  rep(i,n){cin>>s[i];reverse(all(s[i]));}
  vector<pair<int,string>>v(n);
  rep(i,n){
    v[i].first=s[i].size();
    v[i].second=s[i];
  }
  sort(all(v));
  reverse(all(v));
  rep(i,n){
    if(trie.start_with(v[i].second.substr(0,v[i].first-1))){

    }
    trie.insert(v[i].second);
  
  }
  */
  vl dp(51);
  dp[0]=1;
  rep(i,50)dp[i+1]=dp[i]*2+3;
  ll n;cin>>n;ll x;cin>>x;
  ll diff=0;
  ll now=x;
  while(now>0){
      if(now>0){now--;diff--;}
      if(now>=dp[n-1]){now-=dp[n-1];diff++;}
      else {n--;continue;}
      if(now>0){now--;diff++;}
      if(now>=dp[n-1]){now-=dp[n-1];diff++;}
      else {n--;continue;}
      if(now>0){now--;diff--;}
  }
  //cout<<diff<<endl;
  cout<<(x+diff)/2<<endl;
}