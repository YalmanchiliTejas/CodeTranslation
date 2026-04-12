#include <bits/stdc++.h>
using namespace std;
const int maxn = 601;
const string make = "FESTIVA";
long long k;
long long add(long long a, long long b){
	a += b;
	a = min(a, k + 1);
	return a;
}
long long f[8][maxn], c[maxn];
long long subs(string s, string t){
	int len = t.size();
	vector<long long> f(len + 1);
	f[0] = 1;
	for(auto c : s){
		vector<long long> nf = f;
		for(int i = 0; i < len; i++){
			if(c == t[i]){
				nf[i + 1] += f[i];
			}
		}
		f = nf;
	}
	return f.back();
}
int main(){
	cin >> k;
	f[0][0] = 1;
	for(int i = 1; i < maxn; i++){
		f[0][i] = f[0][i - 1];
		for(int j = 1; j < 8; j++){
			f[j][i] = add(f[j - 1][i], f[j][i - 1]);
		}
	}
	long long r = k;
	for(int i = maxn - 1; i >= 1; i--){
		c[i] = r / f[7][i];
		r %= f[7][i];
	}
	string ans;
	for(int i = 1; i < maxn; i++){
		ans += make;
		ans += string(c[i], 'L');
	}
	assert(subs(ans, "FESTIVAL") == k);
	cout << ans << endl;
	return 0;
}
