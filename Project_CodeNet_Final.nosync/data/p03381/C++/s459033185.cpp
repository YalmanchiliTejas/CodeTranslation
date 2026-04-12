//----------------------------おまじない
#pragma GCC optimize ("O3")
#pragma GCC target ("tune=native")
#pragma GCC target ("avx")
//----------------------------
#define FOR(i,j,n) for (int i=(j);i<(n);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define REPN(i,n) for (int i=(n);i>=0;i--)
#define I(n) scanf("%d", &(n))
#define LL(n) scanf("%lld", &(n))
#define pb(n) push_back((n))
#define mp(i,j) make_pair((i),(j))
#define eb(i,j) emplace_back((i),(j))
#include <bits/stdc++.h>
using namespace std;
//------------------------------typedef集
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef vector<vpi> vvpi;
typedef vector<vvi> vvvi;
typedef long long ll;
const int mod = 1000000009;

int n,y[200010];
vi x;

int main(){
    I(n);
    x.resize(n);
    REP(i,n) { I(x[i]); y[i] = x[i]; }
    sort(x.begin(),x.end());
    int xlow = x[n/2-1];
    int xhigh = x[n/2];
    REP(i,n){
        if (y[i] > xlow){
            printf("%d\n",xlow);
        } else {
            printf("%d\n",xhigh);
        }
    }
}