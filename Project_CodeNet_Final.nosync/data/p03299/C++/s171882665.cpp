#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct state {
	int h;
	int w;
	long long ans1 = 2;
	long long ans2 = 0;
	
	state() {}
	state(int h, int w) : h(h), w(w) {}
};

int m = 1000000007;
int h[100];

long long powmod(long long x, long long y) {
	long long ans = 1;
	
	while (y > 0) {
		if (y & 1) ans = ans * x % m;
		x = x * x % m;
		y >>= 1;
	}
	
	return ans;
}

long long mod_inverse(long long a, long long m) {
    long long b = m, x = 1, y = 0;
    
    while (b) {
        long long t = a / b;
        
        a -= t * b;
        x -= t * y;
        
        swap(a, b);
        swap(x, y);
    }
    
    return (m + x % m) % m;
}

long long solve(int l, int r) {
	int i, j;
	long long ans = 1;
	vector <state> v;
	
	if (l == r) return 1;
	
	v.push_back(state(0, 1));
	
	for (i = l; i < r; i++) {
		v.push_back(state(h[i], 1));
	}
	
	v.push_back(state(0, 1));
	
	while (v.size() > 3) {
		int x = 0;
		
		for (i = 0; i < v.size(); i++) {
			if (v[i].h > v[x].h) x = i;
		}
		
		if (v[x].h == v[x + 1].h) {
			long long tmp1, tmp2;
			
			tmp1 = v[x].ans1 * v[x + 1].ans1 % m * mod_inverse(2, m) % m;
			tmp2 = ((v[x].ans1 + v[x].ans2) * (v[x + 1].ans1 + v[x + 1].ans2) - tmp1 + m) % m;
			
			v[x].ans1 = tmp1;
			v[x].ans2 = tmp2;
			v[x].w += v[x + 1].w;
			v.erase(v.begin() + x + 1);
		} else {
			int h = v[x].h - max(v[x - 1].h, v[x + 1].h);
			
			if (v[x].w == 1) {
				ans = ans * powmod(2, h) % m;
			} else {
				v[x].ans1 = v[x].ans1 * powmod(2, h) % m;
			}
			
			v[x].h -= h;
		}
	}
	
	return ans * (v[1].ans1 * powmod(2, v[1].h - 1) % m + v[1].ans2) % m;
}

int main() {
	int n, x = 0, i;
	long long ans = 1;
	
	scanf("%d", &n);
	
	for (i = 0; i < n; i++) scanf("%d", &h[i]);
	
	for (i = 0; i < n; i++) {
		if (h[i] == 1) {
			ans = ans * solve(x, i) * 2 % m;
			x = i + 1;
		}
	}
	
	ans = ans * solve(x, n) % m;
	
	printf("%lld\n", ans);
	
	return 0;
}
