#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline bool chmin(A &a,const B &b){if(a>b){a=b;return true;}else{return false;}}
template<typename A,typename B>inline bool chmax(A &a,const B &b){if(a<b){a=b;return true;}else{return false;}}

ll MOD = 1000000000+7;

int main()
{
    int N;
    cin >> N;
    vll A(N);
    cin >> A;

    ll allsum = 0;
    REP(i,N){
        allsum += A[i];
    }
    vll sums(N);
    ll b = 0;
    REP(i,N){
        b += A[i];
        sums[i] = allsum - b;
        sums[i] %= MOD;
    }
    ll ans = 0;
    REP(i,N-1){
        ans += sums[i]*A[i];
        ans %= MOD;
    }
    cout << ans << endl;
}