#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0 ; i<(n) ; i++)
#define repr(i,n) for(int i=(n) ; i>=0 ; i--)
#define ALL(x) (x).begin(),(x).end()

using ll = long long;
using ull = unsigned long long;
 
const ll INF = 1LL<<60;
const int MINF = 1e9;
const int MOD = 1e9+7;

using vi = vector<int>;
using vii = vector<vi>;

template<typename T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<typename T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

template<typename T>
T GCD(T a,T b){ return b ? GCD(b,a%b) : a ;}
template<typename T>
T LCM(T a,T b){ return a*b / GCD(a,b) ;}

int calc(int n){
    if(n == 1)return 1;
    return 1 + calc(n-1) * 2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin >> n;
    vector<ll> x(n);
    rep(i,n)cin >> x[i];
    vector<ll> t(x);
    sort(ALL(t));
    int t_size = t.size();
    double median = (t[t_size/2] + t[t_size/2-1]) / 2.0;
    for(int i=0;i<t_size;i++){
        if(x[i] > median)cout << t[t_size/2-1] << endl;
        else if(x[i] <= median)cout << t[t_size/2] << endl;
    }
    return 0;
}