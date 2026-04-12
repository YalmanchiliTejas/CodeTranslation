#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PP;
#define MOD 1000000007
//#define MOD 998244353
#define INF 2305843009213693951
//#define INF 810114514
#define PI 3.141592653589
#define setdouble setprecision
#define REP(i,n) for(ll i=0;i<(n);++i)
#define OREP(i,n) for(ll i=1;i<=(n);++i)
#define RREP(i,n) for(ll i=(n)-1;i>=0;--i)
#define all1(i) begin(i),end(i)
#define GOODBYE do { cout << "0" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl
#define debug false
#define debug2 false


int main(void){
    ll N,a;
    ll Asum=0;
    vector<ll> A;
    cin >> N;
    REP(i,N){
        cin >> a;
        Asum+=a;
        A.push_back(a);
    }
    Asum%=MOD;
    ll Ans = (Asum*Asum)%MOD;
    
    REP(i,N){
        Ans = (Ans+MOD-((A[i]*A[i])%MOD))%MOD;
    }
    
    Ans = (Ans*500000004)%MOD;
    cout << Ans << endl;
    
    return 0;
}

