#include"bits/stdc++.h"
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep3(i,m,n) for(int (i)=m;(i)<=(n);(i)++)
#define rep3rev(i,m,n) for(int (i)=m;(i)>=(n);(i)--)
#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define eb emplace_back

using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using P = pair<int, int>;

string s; int k, n;
ll ans = 0;

ll comb(ll N, ll R){
    if(R == 0) return 1;
    if(R == 1) return N;
    if(R == 2) return N*(N-1)/2;
    if(R == 3) return N*(N-1)*(N-2)/6;
    return 0;    
}

ll dfs(int digit, int r_nonzero, bool smaller){
    // digit : 何桁決めたか
    // r_nonzero : 非ゼロをあと何回使うか
    // smaller : n より小さいことが決定しているかどうか
    if(digit == n) {
        if(r_nonzero == 0) return 1;
        else return 0;
    }
    if(r_nonzero == 0){
        return 1;
    }
    if(smaller){
        ll ans = comb(n - digit, r_nonzero) * pow(9, r_nonzero); 
        return ans;        
    }
    int now = s[digit] - '0';
    if(now == 0) return dfs(digit+1, r_nonzero, false);
    ll zero = dfs(digit+1, r_nonzero, true);
    ll between = dfs(digit+1, r_nonzero-1, true) * (now - 1);
    ll same = dfs(digit+1, r_nonzero-1, false);
    return zero + between + same;    
}

void Main() {
    cin >> s >> k;
    n = s.size();
    cout << dfs(0, k, false) << endl;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
	return 0;
}