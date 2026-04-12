#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

const int MOD = 1e9+7; //998244353;
inline int add(int a, int b){ return (a+b)%MOD; }
inline int sub(int a, int b){ return ((a-b)%MOD + MOD)%MOD; }
inline int mul(int a, int b){ return ((ll)a*b)%MOD; }
int pwr(int a, int b){
    if(!b) return 1;
    int temp = pwr(a, b/2);
    if(b%2) return mul(mul(temp, temp), a);
    return mul(temp, temp);
}
inline int dvd(int a, int b){ return mul(a, pwr(b, MOD-2)); } // MOD SHOULD BE PRIME 

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    int sum = 0;
    for(int i = 0; i < n; ++i) sum = add(sum, a[i]);

    int ans = 0;
    for(int i = 0; i < n; ++i){
        int x = sub(sum, a[i]);
        ans = add(ans, mul(a[i], x));
    }
    ans = dvd(ans, 2);

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}