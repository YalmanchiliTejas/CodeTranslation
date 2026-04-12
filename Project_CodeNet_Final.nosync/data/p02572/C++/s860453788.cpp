#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;
ll mod = 1e+9 + 7;

int main(){
    ll N;
    cin >> N;

    ll A[N], B[N];
    REP(i, N){
        int a;
        cin >> a;
        A[i] = a%mod;
        if(i == 0) B[i] = A[i];
        else{
            B[i] = B[i-1] + A[i];
            B[i] = B[i]%mod;
        }
    }
    
    ll ans = 0;
    REP(i, N-1){
        ans += A[i+1]*B[i];
        ans = ans%mod;
    }   


    cout << ans << endl;

    return 0;
}
