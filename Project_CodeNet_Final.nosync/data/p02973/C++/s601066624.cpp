#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define SORT(v,n) sort(v,v+n)
#define rep(i,n) FOR(i,0,n)
#define EPS (1e-7)
#define INF (1e9)

using namespace std;
typedef long long int ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int,int> PI;
typedef pair<ll,ll> PL;
typedef priority_queue<int> PQI;
typedef priority_queue<int,vector<int>,greater<int> > PQSI;
typedef priority_queue<ll> PQL;
typedef priority_queue<ll,vector<ll>,greater<ll> > PQSL;

const int MOD = 1000000007;
struct mint { int n; mint(int n_ = 0) : n(n_) {} };
mint operator-(mint a) { return -a.n + MOD * (a.n != 0); }
mint operator+(mint a, mint b) { int x = a.n + b.n; return x - (x >= MOD) * MOD; }
mint operator-(mint a, mint b) { int x = a.n - b.n; return x + (x < 0) * MOD; }
mint operator*(mint a, mint b) { return (long long)a.n * b.n % MOD; }
mint &operator+=(mint &a, mint b) { return a = a + b; }
mint &operator-=(mint &a, mint b) { return a = a - b; }
mint &operator*=(mint &a, mint b) { return a = a * b; }
istream &operator>>(istream &i, mint &a) { return i >> a.n; }
ostream &operator<<(ostream &o, mint a) { return o << a.n; }

vector<mint> F_{1, 1}, R_{1, 1}, I_{0, 1};
void check_fact(int n) {
  for (int i = I_.size(); i <= n; i++) {
    I_.push_back(I_[MOD % i] * (MOD - MOD / i));
    F_.push_back(F_[i - 1] * i);
    R_.push_back(R_[i - 1] * I_[i]);
  }
}

mint I(int n) { check_fact(abs(n)); return n >= 0 ? I_[n] : -I_[n]; }
mint F(int n) { check_fact(n); return n < 0 ? 0 : F_[n]; }
mint R(int n) { check_fact(n); return n < 0 ? 0 : R_[n]; }
mint C(int n, int r) { return F(n) * R(n - r) * R(r); }
mint P(int n, int r) { return F(n) * R(n - r); }
mint H(int n, int r) { return n == 0 ? (r == 0) : C(n + r - 1, r); }

template<typename T>
T gcd(T x, T y){
    if (y == 0) return x;
    else return gcd(y, x % y);
}

template<typename T>
T lcm(T x, T y){
    return (x / gcd(x, y)) * y;
}

template<typename T>
T ceil(T x, T y){
    return (x + (y - 1)) / y;
}

int N;
int A[100000];
int main(void){
    cin >> N;
    rep(i,N) scanf("%d",&A[i]);
    vector<int> v;
    v.push_back(A[0]);
    for(int i=1;i<N;i++){
        int index = lower_bound(v.begin(), v.end(), A[i]) - v.begin() - 1;
        if(index == -1) {
            v.insert(v.begin(), A[i]);
        }else if(index == v.size() - 1 and A[i] == v[index]){
            v.push_back(A[i]);
        }
        else{
            v[index] = A[i];
        }
        /*
        int tmp = 0;
        while(true){
            if(tmp >= v.size()){
                v.push_back(A[i]);
                break;
            }
            if(v[tmp] < A[i]){
                v[tmp] = A[i];
                break;
            }
            tmp++;
        }
        */
    }
    cout << v.size() << endl;

    return 0;
}









