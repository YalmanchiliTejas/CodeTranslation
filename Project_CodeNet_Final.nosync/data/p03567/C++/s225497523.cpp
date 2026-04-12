#include <bits/stdc++.h>
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define SORTR(v,n) sort(v, v+n, greater<int>());
#define SORTPairSecond(v, n) sort(v, v+n, pairCompareSecond);
#define int long long    // %d=>%lld, 1<<n  => 1LL<<n
#define pb push_back

using namespace std;
typedef long long ll;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> piii;
typedef pair<ll, pll> plll;
bool pairCompareSecond(const pii& firstEl, const pii& secondEl) {
    return firstEl.second > secondEl.second;
}

const ll MOD = 1000000007;
const int INF = 1000000007;
// const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
// const ll LLINF = 1LL << 50;
const double PI = acos(-1);
const double EPS = 0.000000001;


string s;


signed main(){
    ios::sync_with_stdio(0);

    cin >> s;
    if(std::string::npos == s.find("AC")){
        cout<< "No\n";
        
    }else{
        cout<< "Yes\n";
        
    }



    return 0;
}