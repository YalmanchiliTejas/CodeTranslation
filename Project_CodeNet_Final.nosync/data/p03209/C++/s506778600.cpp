#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <numeric>
#include <list> 

using namespace std;
using ll = long long;
#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(x) x.begin(),x.end()
#define INF (1e9)

#define CAPITAL
void Yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<endl;
	#else
	cout<<"Yes"<<endl;
	#endif
	if(ex)exit(0);
}
void No(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<endl;
	#else
	cout<<"No"<<endl;
	#endif
	if(ex)exit(0);
}

long long dp(int l ,ll x, vector<ll> vi,  vector<ll> ci) {
    if (x <= 0) return 0;
    if (l == 0) return 1;
    if (vi[l - 1] + 1 >= x) {
        return dp(l - 1, x - 1, vi, ci);
    } else {
        return 1 + ci[l - 1] + dp(l - 1, x - 2 - vi[l-1], vi, ci);
    }
    return 0;
}
int main() {
	int n;
    ll x;
	cin >> n >> x;
    vector<ll> vi(n + 2);
    vector<ll> ci(n + 2);
    REP(i, n + 2) {
        if (i == 0) vi[i] = 1;
        else vi[i] = vi[i - 1] * 2 + 3;
        if (i == 0) ci[i] = 1;
        else ci[i] = ci[i - 1] * 2 + 1;
    }
    printf("%lld", dp(n, x, vi, ci));
}