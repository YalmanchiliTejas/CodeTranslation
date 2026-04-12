#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define fi first
#define se second
#define mp make_pair
#define itrfor(itr,A) for(auto itr = A.begin(); itr !=A.end();itr++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;
typedef long long llong;
char moji[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char moji2[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char moji3[10]={'0','1','2','3','4','5','6','7','8','9'};
#define Sort(a) sort(a.begin(),a.end());
#define Reverse(a) reverse(a.begin(),a.end());
#define print(a) cout << a << endl;
#define MOD llong(998244353)
#define MAX int(2 * 1e5 +5)
#define debug(x)  cout << #x << " = " << (x) << endl;
#define pi acos(-1.0)
#define int llong
#define INF llong(1e18 + 3)
template<class T> bool chmax(T &a,  T b) {if(a<b){a=b; return 1;} return 0;}
template<class T> bool chmin(T &a,  T b) {if(a>b){a=b; return 1;} return 0;}
bool Add(int &a,int b){a = (a + b) % MOD;}
void myprint(int* A,int A_num){
   REP(i,A_num) cout << A[i] << " ";
   cout << endl;
}


llong bek(llong a,llong x){
    llong res = 1;
    llong tmp = a;
    while(x > 0){
        if(x & 1) res *= tmp; res %= MOD;
        tmp *= tmp;
        tmp %= MOD;
        x >>=1;
    }
    return res;
}

signed main(){
    int n;
    cin >> n;
    int zentai = 1;
    REP(i,n){
        zentai *= 3;
        zentai %= MOD;
    }
    int beki = 1;
    REP(i,n/2){
        beki *= 2;
        beki %= MOD;
    }


    int hidari, migi;
    hidari = 1;
    migi = 0;
    int ans = 0;
    int beki2 = 1;
    int gyaku2 = bek(2,MOD - 2);
    FOR(i,1,n / 2 + 1){
        int huga = hidari * beki2;
        huga %= MOD;
        migi += huga;
        migi %= MOD;

        beki2 *= 2;
        beki2 %= MOD;

        hidari *= n / 2 + 1 - i;
        hidari %= MOD;
        hidari *= bek(i,MOD - 2);
        hidari %= MOD;
       
        beki *= gyaku2;
        beki %= MOD;
        int hoge = migi * hidari;
        hoge %= MOD;
        hoge *= beki;
        hoge %= MOD;
        ans += hoge;
        ans %= MOD;
    }

    cout << (zentai + 2 * MOD - 2 * ans ) % MOD << endl;


}