#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;

template<class T>bool chmax(T &a, const T &b) { if( a < b ) { a = b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) { if( b < a ) { a = b; return 1; } return 0;}

#ifdef LOCAL
	#define eprintf(...) printf(__VA_ARGS__)
#else
	#define eprintf(...) 1
#endif

#define ROUNDUP(a, b) 		( ((a) + ((b) - 1) ) / b)
#define SET_ZERO(a)	 		( memset((a), 0, sizeof(a)))
#define SET_NUM_ARRAY(a,b)	( memset((a), b, sizeof(a)))
//#define int long long int //dont forget to change int to signed
int count16bit(unsigned short v) {
	unsigned short count = (v & 0x5555) + ((v >> 1) & 0x5555);
	count = (count & 0x3333) + ((count >> 2) & 0x3333);
	count = (count & 0x0f0f) + ((count >> 4) & 0x0f0f);
	return (count & 0x00ff) + ((count >> 8) & 0x00ff);
}

int main() {
	int N, M;
	vector<int> vv[8];
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vv[a-1].push_back(b-1);
		vv[b-1].push_back(a-1);
	}

	stack<ii> st;
	st.push(ii(0,1));
	int ans = 0;
	while (!st.empty()) {
		ii p = st.top(); 
		int v = p.first, bit = p.second;
		st.pop();
		eprintf("v = %d bit = %d\n", v, bit);
		if (count16bit(bit) == N) {
			ans++;
			continue;
		}
		for (vector<int>::iterator it = vv[v].begin(); it != vv[v].end(); ++it) {
		// for (auto it: vv[v]) {
			int s = *it;
			if (!(bit & (1<<s))) {
				st.push(ii(s,bit | (1<<s) ));
			}
		}
	}
	printf("%d \n", ans);
	return 0;
}
