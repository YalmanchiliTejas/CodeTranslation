// include
// ------------------------------------------------
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

// func
// ------------------------------------------------
int CalcSumOfDigit(int n);      // 各桁の和を計算する。
int getDigit(int n);            // 数字の桁数を取得する。
string upper(string str);       // 英字を大文字に変換する。
string lower(string str);       // 英字を小文字に変換する。
vector<pair<long long,long long>> prime_factorize(long long p); // 素因数分解
vector<pair<char, long long>> runLengthEncoding(string s);      // ランレングス圧縮
long long grid_bfs(vector<string> &m, long long s_r, long long s_c, long long g_r ,long long g_c ,char block); // gridのbfs

// class
// ------------------------------------------------
class Combi {
  public:
    Combi();
    long long Combination(long long n, long long k);
    long long nPk_modp(long long n, long long k, long long p);
  private:
    map<long long, map<long long, long long>> memo;
    long long n_num;
    long long k_num;
};

// define
// ------------------------------------------------
#define all(a)        (a).begin(),(a).end()
#define rall(a)       (a).rbegin(),(a).rend()
#define sz(a)         int((a).size())
#define rep(i,n)      for(long long(i)=0;(i)<(n);(i)++)
#define repe(i,n)     for(long long(i)=0;(i)<=(n);(i)++)
#define vsort(v)      sort((v).begin(),(v).end())
#define rvsort(v)     sort(rall((v)))
#define vi            vector<int>
#define GCD(a,b)      __gcd((a),(b))
#define LCM(a,b)      (a)/GCD((a),(b))*(b)
#define kiriage(a,b)  ((a)+(b)-1)/(b)

const int INF = 1e9;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vll;


#include <cstdint>

template <long long Modulus> class modint {
    public:
        long long val;
        modint(long long v = 0) : val(v % Modulus){
            if(val < 0) val += Modulus;
        }

        // =付きの演算子に処理を任せる
        modint operator + (const modint& rhs) { return modint(*this) += rhs; }
        modint operator - (const modint& rhs) { return modint(*this) -= rhs; }
        modint operator * (const modint& rhs) { return modint(*this) *= rhs; }
        modint operator / (const modint& rhs) { return modint(*this) /= rhs; }

        modint operator = (const long long& rhs) {
            val = rhs;
            val = val % Modulus;
            cout << "a" << endl;
            return modint(*this);
        }

        modint& operator += (const modint& rhs) {
            // まず足してみて、Modulusを超えてくるようなら引く
            val += rhs.val;
            if(val >= Modulus) val -= Modulus;
            return *this;
        }

        modint& operator -= (const modint& rhs){
            // 負になっちゃったら足す
            val -= rhs.val;
            if( val < 0 ) val += Modulus;
            return *this;
        }

        modint& operator *= (const modint& rhs){
            // modintな時点でvalは %Modulus しているのでこれでよい。
            val = val * rhs.val % Modulus;
            return *this;
        }

        modint& operator /= (const modint& rhs){
            return *this *= inv(rhs);
        }

        // ! TODO: inverseを作っておく
        long long extGCD(long long a,long long b, long long &x,long long &y){
            if(b == 0){
                x = 1;
                y = 0;
                return 0;
            }

            long long d = extGCD(b, a % b, y, x);

            y -= a/b * x;

            return d;
        }

        modint inv(const modint& rhs){
            ll u,v;
            extGCD(rhs.val, Modulus, u, v);
            return modint(u);
        }
        

        bool operator == (const modint& rhs){
            return this->val == rhs.val;
        }

        bool operator != (const modint& rhs){
            return this->val != rhs.val;
        }

        // TODO: iostreamをつくっておく？

};

using mint = modint<1000000007>;

// code
// ------------------------------------------------
ll solve(deque<ll> deq, bool flg_hl){
    deque<ll> a_deq;

    if(flg_hl){
        a_deq.push_back(deq.back());
        deq.pop_back();
    } else {
        a_deq.push_back(deq.front());
        deq.pop_front();
    }

    flg_hl = !flg_hl;

    bool flg_fr = true; // frontからいれる？
    while((int)deq.size()){
        ll buf;
        
        // 高い方
        if(flg_hl){
            buf = deq.back();
            deq.pop_back();
        } else {
            buf = deq.front();
            deq.pop_front();
        }

        if(flg_fr){
            a_deq.push_front(buf);
        } else {
            a_deq.push_back(buf);
            flg_hl = !flg_hl;
        }

        flg_fr = !flg_fr;
    }

    ll ans = 0;
    ll bef = a_deq.front();
    a_deq.pop_front();
    while((int)a_deq.size()){
        ans += abs(bef - a_deq.front());
        bef = a_deq.front();
        a_deq.pop_front();

    }

    return ans;
}


int main() {

    ll n;
    cin >> n;
    vll a(n);
    rep(i,n) cin >> a[i];
    vsort(a);

    deque<ll> deq;

    rep(i,n){
        deq.push_back(a[i]);
    }

    ll hi = solve(deq,true);
    ll lo = solve(deq,false);

    ll ans = max(hi,lo);

    cout << ans << endl;

    return 0;
}



// funcの実体
// ------------------------------------------------
int getDigit(int n) {
  int i = 1;
  while(1) {
    n = n / 10;
    if(n == 1)
      break;
    i++;
  }
  return i;
}
int CalcSumOfDigit(int n) {
  int s = 0;
  while(n) {
    s += n % 10;
    n = n / 10;
  }
  return s;
}

string upper(string str) {
  for(auto itr = str.begin();itr != str.end() ; itr++) {
    if(97 <= *itr && *itr <= 122) {
      *itr = *itr - 32;
    }
  }
  return str;
}

string lower(string str) {
  for(auto itr = str.begin();itr != str.end() ; itr++) {
    if(65 <= *itr && *itr <= 90) {
      *itr = *itr + 32;
    }
  }
  return str;
}


Combi::Combi() {
  n_num = -1;
  k_num = -1;
};

ll Combi::Combination(ll n, ll k) {

  ll ret;
  if(memo[n][k] != 0) {
    ret = memo[n][k];
  } else if(n == k || k == 0) {
    memo[n][k] = 1;
    ret = 1;
  } else {
    ret = Combination(n - 1, k - 1) + Combination(n - 1, k);
    memo[n][k] = ret;
  }
  return ret;
}

long long Combi::nPk_modp(long long n, long long k, long long p) {
  ll ans = 1;
  for(long long i = k; i <= n; i++) {
    ans = (ans * i) % p;
  }

  return ans;
};

vector<pair<long long,long long>> prime_factorize(long long p) {
    vector<pair<long long,long long>> ret;

    for(long long x = 2; x * x <= p; ++x) {
        if(p % x != 0) continue;
        long long num = 0;
        while(p % x == 0) {
            num++;
            p /= x;
        }
        ret.push_back(make_pair(x,num));
    }

    if(p != 1) ret.push_back(make_pair(p, 1));
    
    return ret;
}

vector<pair<char, long long>> runLengthEncoding(string s){
    vector<pair<char, long long>> ret;
    
    for(long long i = 0; i < s.length(); i++){
        char cur = s[i];
        long long cnt = 1;

        for(long long j = i + 1; j < s.length(); j++){
            if(cur != s[j]) break;
            
            cnt++;
        }

        ret.emplace_back(make_pair(cur,cnt));

        i += cnt - 1;
    }

    return ret;
}

// bfsをしてgoalまでの距離を調べる
long long grid_bfs(vector<string> &m, long long s_r, long long s_c, long long g_r ,long long g_c ,char block = '#'){

    // 訪問済み管理テーブルを作る
    long long r = sz(m);
    long long c = sz(m[0]);
    vector<vector<long long>> dist(r,vector<long long>(c,-1));

    // queueを使ってbfsをする。
    queue<pair<long long, long long>>   q;
    long long grid_dict[][2] = {
        { 1  , 0  }, // up
        { -1 , 0  }, // down
        { 0  , 1  } , // right
        { 0  , -1 }  // left
    };

    q.push(make_pair(s_r, s_c));
    dist[s_r][s_c] = 0;


    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        rep(i,4){
            long long ver = cur.first + grid_dict[i][0];
            long long hor = cur.second + grid_dict[i][1];

            // mapの範囲内で、壁じゃなくて、訪問済じゃない場合は、
            // 距離を記録して訪問予定リストに追加する
            if(( 0 <= ver && ver < r)
                && ( 0 <= hor && hor < c)
                && ( m[ver][hor] != block )
                && ( dist[ver][hor] == -1 )
            ){
                dist[ver][hor] = dist[cur.first][cur.second] + 1;
                q.push(make_pair(ver,hor));
            }
        }
    }

    return dist[g_r][g_c];
}
