#include <bits/stdc++.h>

using namespace std;

const long long MOD=998244353;

long long add_mod(long long x,long long y){
	return (x+y)%MOD;
}

long long sub_mod(long long x,long long y){
	return (x-y+MOD)%MOD;
}

long long mul_mod(long long x,long long y){
	return x*y%MOD;
}

int n,s;
long long c[3001][3001];

void solve(){
    int i,j;
    string str;
    cin >> n >> s;
    vector<long long> a(n);
    for(i = 0;i < n;i++) cin >> a[i];
    long long ans = 0;
    for(i = 0;i < n;i++){
        for(j = 0;j <= s;j++){
            c[i+1][j] = c[i][j];
        }
        c[i+1][0] = add_mod(c[i+1][0],1);
        for(j = s-a[i];j >= 0;j--){
            c[i+1][j+a[i]] = add_mod(c[i+1][j+a[i]],c[i+1][j]);
        }
        ans = add_mod(ans,mul_mod(c[i+1][s],n-i));
        c[i+1][s] = 0;
    }
    cout << ans << endl;
}

int main(){
    solve();
}
