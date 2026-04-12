#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
//ループ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//コンテナ
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
#define D()
//定数
#define INF 1000000000000 //10^12
#define MOD 10000007 //10^9+7
#define MAXR 100000 //10^5:配列の最大のrange(素数列挙などで使用)
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素

//2値の最大公約数(順序関係なし・0はダメ)
int gcd(int a, int b){
    return b ? gcd(b, a%b) :a;
}

//n個の最大公約数
int ngcd(vector<int>& a){
    int res;
    res = a.at(0);
    for(int i = 1; i< a.size() && res != 1; i++){
        res = gcd(a.at(i), res);
    }
    return res;
}

//2値の最小公倍数
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

//n個の最小公倍数
int nlcm(vector<int> numbers){
    int res;
    res = numbers.at(0);
    for(int i = 0; i< numbers.size();i++){
        res = lcm(res, numbers[i]);
    }
    return res;
}

//素数判定O(√N)
bool isPrime(int x){
    if(x<2) return 0;
    else if(x == 2) return 1;
    if(x%2 == 0) return 0;
    for(int i = 3; i*i <= x; i+=2) if(x%i == 0) return 0;
    return 1;
}

//桁和
int digsum(int n){
    int res = 0;
    while(n>0){
        res += n%10;
        n /= 10;
    }
    return res;
}

//約数全列挙
vector<int> enum_div(int n){
    vector<int> ret;
    for(int i = 1 ; i*i <= n ; ++i){
        if(n%i == 0){
            ret.push_back(i);
            if(i != 1 && i*i != n){
                ret.push_back(n/i);
            }
        }
    }
    return ret;
}

//繰り返し自乗法
long long int mod_pow(long long int x, long long int n, long long int mod){
    long long int res = 1;
    while(n > 0){
        if(n & 1) res = res*x%mod;
        x = x*x%mod;
        n >>= 1;
    }
    return res;
}

//文字列の中で何回文字が出てきたのかを数える
int stringcount(string s, char c) {
    return count(s.cbegin(), s.cend(), c); //覚える
}

int main(){
    int x; cin >> x;
    if(x>=30) cout << "Yes" << endl;
    else cout << "No" << endl;
}