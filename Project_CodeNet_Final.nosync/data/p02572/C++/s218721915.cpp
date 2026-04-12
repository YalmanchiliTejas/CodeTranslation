#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin >> n;
    vector<ll>a(n);
    REP(i,n)cin >> a[i];
    ll answer = 0;
    vector<ll> total_sum(n);
    total_sum[0]=0;
    FOR(i,1,n){
        total_sum[i]=(total_sum[i-1]+a[n-i])%MOD;
    }
    reverse(ALL(total_sum));
    REP(i,n){
        answer = (answer+(a[i]*total_sum[i])%MOD)%MOD;
    }

    cout << answer << endl;
    return 0;
}