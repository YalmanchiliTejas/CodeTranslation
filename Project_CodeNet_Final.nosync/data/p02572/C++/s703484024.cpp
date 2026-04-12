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
    int n;
    cin >> n;
    vector<ll>a(n);
    vector<ll>sum(n+1);
    sum[0]=0;
    REP(i,n)cin >> a[i];
    FORR(i,n-1,0)sum[n-i]=(sum[n-i-1]+a[i])%MOD;
    ll answer=0;
    REP(i,n){
        answer = (answer+(a[i]*sum[n-i-1])%MOD)%MOD;
    }
    cout << answer << endl;
    return 0;
}