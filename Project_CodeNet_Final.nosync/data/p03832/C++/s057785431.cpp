#include <iostream>
#include <algorithm>

long long mod_inv_buf[1001];
bool mod_inv_flag[1001];
long long mod_inv(long long value, long long m){
	long long r0 = m, r1 = value;
	if(mod_inv_flag[value])
		return mod_inv_buf[value];
	mod_inv_flag[value] = true;

	long long m0[2][2] = {{0, 1}, {1, -r0 / r1}}, m1[2][2];
	r0 = r0 % r1;
	std::swap(r0, r1);
	if(r1 == 0)
		return mod_inv_buf[value] = m0[0][1] >= 0 ? m0[0][1] : m0[0][1] + m;

	while(1){
		long long k = -r0 / r1;
		m1[0][0] = m0[1][0];
		m1[0][1] = m0[1][1];
		m1[1][0] = m0[0][0] + k * m0[1][0];
		m1[1][1] = m0[0][1] + k * m0[1][1];
		r0 = r0 % r1;
		std::swap(r0, r1);
		if(r1 == 0)
			return mod_inv_buf[value] = m1[0][1] >= 0 ? m1[0][1] : m1[0][1] + m;
		k = -r0 / r1;
		m0[0][0] = m1[1][0];
		m0[0][1] = m1[1][1];
		m0[1][0] = m1[0][0] + k * m1[1][0];
		m0[1][1] = m1[0][1] + k * m1[1][1];
		r0 = r0 % r1;
		std::swap(r0, r1);
		if(r1 == 0)
			return mod_inv_buf[value] = m0[0][1] >= 0 ? m0[0][1] : m0[0][1] + m;
	}
}

#define M 1000000007

long long fact[1001];
long long afact[1001];

long long buf[1001][1001];
bool mark[1001][1001];
long long n, a, b, c, d;

long long calc(int x, int y){
	if(mark[x][y])
		return buf[x][y];
	if(x < a){
		return y == 0 ? 1 : 0;
	}
	long long sum = calc(x - 1, y);
	for(int i = c; i <= d && x * i <= y; i++){
		long long t = calc(x - 1, y - x * i);
		long long tt = (fact[n - y + x * i] * afact[n - y]) % M;
		t = (t * tt) % M;
		tt = afact[x];
		for(long long j = 0; j < i; j++){
			t = (t * tt) % M;
		}
		t = (t * afact[i]) % M;
		sum = (sum + t) % M;
	}
	mark[x][y] = true;
	buf[x][y] = sum;
	return sum;
}

int main(int argc, char *argv[]){
	afact[0] = fact[0] = 1;
	for(int i = 1;i <= 1000; i++){
		fact[i] = (fact[i - 1] * i) % M;
		afact[i] = (afact[i - 1] * mod_inv(i,M)) % M;
	}
	std::cin >> n >> a >> b >> c >> d;
	std::cout << calc(b, n) << std::endl;
	return 0;
}
