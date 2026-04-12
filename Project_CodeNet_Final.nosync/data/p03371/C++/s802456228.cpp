#include<bits/stdc++.h>
#include<cmath>
#pragma GCC optimize("Ofast")
using namespace std;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
typedef long long ll;
const ll MOD = 1e9+7;
#define rep(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define REP(i,num,n) for(ll i=num, i##_len=(n); i<i##_len; ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};
#define print(x) (cout << (x) << endl)
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
#define fs first
#define sc second


const int INF = 1e9;
const ll LLINF = 1e16;

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}
 
template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}
 
template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value!=0>::type
fill_v(U &u,const V... v){u=U(v...);}
 
template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value==0>::type
fill_v(U &u,const V... v){
  for(auto &e:u) fill_v<T>(e,v...);
}
 
template<typename T>
T gcd(T a,T b){return b?gcd(b,a%b):a;}

template<typename T>
T ngcd(vector<T> a){
    T res;
    res = a[0];
    for(int i = 1; i < a.size() && res != 1; i++) {
        res = gcd(a[i], res);
    }
    return res;
}
 
template<typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

template<typename T>
T nlcm(vector<T> numbers) {
    T res;
    res = numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
        res = lcm(res, numbers[i]);
    }
    return res;
}

// 割り算の切り上げ処理
template<typename T>
T round_up(T a, T b) {
  return (a + b - 1) / b;
}

// 約数列挙
template<typename T>
vector<T> calc_divisor(T n) {
   vector<T> res;
   for (T i = 1LL; i*i <= n; ++i) {
       if (n % i == 0) {
           res.push_back(i);
           T j = n / i;
           if (j != i) res.push_back(j);
       }
   }
   sort(res.begin(), res.end());
   return res;
}

// 素数判定
template<typename T>
bool isPrime(T x){
    T i;
    if(x < 2)return 0;
    else if(x == 2) return 1;
    if(x%2 == 0) return 0;
    for(i = 3; i*i <= x; i += 2) if(x%i == 0) return 0;
    return 1;
}

// 桁和
template<typename T>
T digsum(T n) {
    T res = 0;
    while(n > 0) {
        res += n%10;
        n /= 10;
    }
    return res;
}

// 指定した文字cが文字列に何文字入ってるか
ll stringcount(string s, char c) {
    return count(s.cbegin(), s.cend(), c);
}


using pint = pair<int, int>;
using pll = pair<ll, ll>;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

int n;

void dfs(int i, string s) {
    if(i == n) {
        print(s);
        return; 
    }
    dfs(i + 1, s + 'a');
    dfs(i + 1, s + 'b');
    dfs(i + 1, s + 'c');
}

int main(void)
{
    cout.tie(0);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    //auto dp=make_v<int>(4,h,w);
    //fill_v(dp,0);
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans = LLINF;
    ll ab = c * 2;
    rep(i, 100001){
        ll sum = 0;
        if(x >= i && y >= i) sum = i * ab + a * (x - i) + b * (y - i);
        else if(x >= i) sum = i * ab + a * (x - i);
        else if(y >= i) sum = i * ab + b * (y - i);
        else sum = i * ab;
        chmin(ans, sum);
    }
    print(ans);
}
