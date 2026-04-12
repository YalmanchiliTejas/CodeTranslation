#include <bits/stdc++.h>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
LL z = 1;
int read(){
	int x, f = 1;
	char ch;
	while(ch = getchar(), ch < '0' || ch > '9') if(ch == '-') f = -1;
	x = ch - '0';
	while(ch = getchar(), ch >= '0' && ch <= '9') x = x * 10 + ch - 48;
	return x * f;
}
int ksm(int a, int b, int p){
	int s = 1;
	while(b){
		if(b & 1) s = z * s * a % p;
		a = z * a * a % p;
		b >>= 1;
	}
	return s;
}
string s[105], ans[105], t;
int cnt, tot;
int ok(string s){
	for(int i = 0; i < s.size(); i++) if(s[i] == '#') return 1;
	return 0;
}
int main(){
	int i, j, n, m;
	n = read(); m = read();
	for(i = 0; i < n; i++){
		cin >> t;
		if(ok(t)) s[cnt++] = t;
	}
	for(i = 0; i < m; i++){
		t = "";
		for(j = 0; j < cnt; j++) t += s[j][i];
		if(ok(t)) ans[tot++] = t;
	}
	for(i = 0; i < cnt; i++){
		for(j = 0; j < tot; j++) cout << ans[j][i];
		printf("\n");
	}
	return 0;
}