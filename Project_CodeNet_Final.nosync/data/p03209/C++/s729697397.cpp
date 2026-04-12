#include <bits/stdc++.h>
#define LL long long
#define db double
using namespace std;
 
const int MAXN = 200200;
const int MAXE = 400400;
const int INF = 0x3f3f3f3f;
 
template<typename T> inline void CheckMax(T &A, T B) {
	A < B ? A = B : A;
}
 
template<typename T> inline void CheckMin(T &A, T B) {
	A > B ? A = B : A;
}
 
template <typename T> inline void read(T &x) {
    int c = getchar();
    bool f = false;
    for (x = 0; !isdigit(c); c = getchar()) {
        if (c == '-') {
            f = true;
        }
    }
    for (; isdigit(c); c = getchar()) {
        x = x * 10 + c - '0';
    }
    if (f) {
        x = -x;
    }
}
 
LL n;
long long k;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
#define X first
#define Y second
 
LL num[100], len[100], add[100], ans;
 
int Find(LL x) {
	for(int i = 50; i >= 0; i--) {
		if(x >= len[i]) return i;
	}
	return -1;
}
 
signed main() {
	read(n), read(k);
	num[0] = len[0] = 1;
	for(int i = 1; i <= 50; i++) num[i] = num[i - 1] * 2 + 1;
	for(int i = 1; i <= 50; i++) len[i] = len[i - 1] * 2 + 3;
	if(k == len[n]) {
		cout << num[n] << endl;
		return 0;
	}
	long long l = 1, m = n - 1;
	while(l < k) {
		if(l == k) break;
		for(LL i = m; i >= 0; i--) {
			if(k >= len[i] + l) {
				ans += num[i];
				l += len[i];
				m = i;
				break;
			}
			l++;
			if(l == k) break;
		}
		if(l == k) break;
		ans++, l++;
		if(l == k) break;
	}
	cout << ans << endl;
	return 0;
}