#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define print(s) cout << s << endl
#define acc(v) accumulate(v.begin(), v.end(), 0)
#define cinv(n,v) rep(i,n) cin >> v[i]
using namespace std;
const int INF = 1e9;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef vector<char> vchar;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
// const lint MOD = 998244353;
int x_pos[4] = {1,0,-1,0}, y_pos[4] = {0,1,0,-1};
int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

char upper(char c){
	return c-0x20;
}

char lower(char c){
	return c+0x20;
}

void unique_vector(vector<int>& v){
	sort(all(v));
	v.erase(unique(all(v)), v.end());
}

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}


ll l[55],p[55];

ll solve(ll n,ll x){
    if(n==0){
        return 1;
    }
    if(x<=1){
        return 0;
    }else if(x < l[n-1]+2){
        return solve(n-1,x-1);
    }else if(x==l[n-1]+2){
        return p[n-1]+1;
    }else if(x < l[n]){
        return solve(n-1,x-l[n-1]-2)+p[n-1]+1;
    }else{
        return p[n];
    }
}

int main() {
    ll n,x;cin>>n>>x;
    l[0]=1;p[0]=1;
    rep(i,n){
        l[i+1] = l[i]*2+3;
        p[i+1] = p[i]*2+1;
    }

    ll ans = solve(n,x);
    cout << ans << endl;
}

