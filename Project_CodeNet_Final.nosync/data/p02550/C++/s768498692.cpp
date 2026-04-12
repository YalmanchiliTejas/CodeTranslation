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

int main(){
    ll N, X, M;
    cin >> N >> X >> M;
    set<ll> s;
    s.insert(X);
    
    vector<ll> cyc(M+1);
    cyc[0] = X;
    ll tmp = X;
    ll ind = 1;
    while(true){
        tmp = tmp * tmp % M;
        cyc[ind] = tmp;
        if(s.count(tmp)){
            break;
        }
        else{
            s.insert(tmp);
        }
        ind++;
    }

    ll st, en;
    en = ind;
    for (int i = 0; i < en; i++) {
        if(cyc[i] == tmp){
            st = i;
            break;
        }
    }
    ll len = en - st;
    ll ans = 0;
    for (ll i = 0; i < st; i++) {
        ans += cyc[i];
    }
    ll cy = 0;
    for (ll i = st; i < en; i++) {
        cy += cyc[i];
    }
    ans += cy * ((N - st) / len);
    ll p = (N - st) % len;
    for (ll i = st; i < st+p; i++) {
        ans += cyc[i];
    }
    printf("%lld\n", ans);


}