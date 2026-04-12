#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll one = 1;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

vector<long long> a, p;

long long f(ll N, ll X){
    if(X == 0){
        return 0;
    }
    else if(N == 0){
        return 1;
    }
    else if(X <= a[N-1] + 1){
        return f(N-1, X-1);
    }
    else{
        return p[N-1] + 1 + f(N-1, X - a[N-1] - 2);
    }
}

int main(){
    a.resize(51); p.resize(51);
    a[0] = 1;
    p[0] = 1;
    for (ll i = 1; i < 51; i++) {
        a[i] = 2 * a[i-1] + 3;
        p[i] = 2 * p[i-1] + 1;
    }
    ll N, X;
    cin >> N >> X;
    printf("%lld\n", f(N, X));

}