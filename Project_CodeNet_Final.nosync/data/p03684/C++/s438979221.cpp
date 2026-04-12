#include <bits/stdc++.h>
using namespace std;

#define LL 					long long
#define ULL 				unsigned long long
#define pii 				pair<int,int>
#define fi 					first
#define se 					second
#define mp 					make_pair
#define vi 					vector<int>
#define psb 				push_back
#define ppb 				pop_back
#define all(x)			 	(x).begin(),(x).end()
#define sz(x)				(int)(x).size()
#define endln 				printf("\n")
#define gc					getchar_unlocked
#define setmin(x)			memset((x), -1, sizeof((x)))
#define setnul(x)			memset((x), 0, sizeof((x)))
#ifndef getchar_unlocked
#define getchar_unlocked 	getchar
#endif
const int inf = (1<<30)-1+(1<<30);
const int mod = 1e9 + 7;

template <typename T>
void gi(T &ret) {
	ret = 0; char inp=gc(); int kl=1;
	while (inp<'0' || inp>'9') {if (inp=='-') kl=-1; inp=gc();}
	while ('0'<=inp && inp<='9') ret=(ret<<3)+(ret<<1)+(inp-'0'), inp=gc();
	if (kl<1) ret=-ret;
}

const int MAXN = 1e5+5;
int n, x[MAXN], y[MAXN], id[MAXN], p[MAXN];
bool cmpx (int a, int b) {
	return x[a]<x[b];
}
bool cmpy (int a, int b) {
	return y[a]<y[b];
}

vector < pair< int , pii > > all;

int fs (int x) {
	if (x!=p[x]) return p[x] = fs(p[x]);
	return x;
}

int main() {
	gi(n);
	for (int i=1; i<=n; i++) {
		gi(x[i]); gi(y[i]);
		id[i] = i; p[i] = i;
	}
	sort(id+1, id+1+n, cmpx);
	for (int i=2; i<=n; i++) {
		int now = id[i], bef = id[i-1];
		all.psb({x[now]-x[bef], {now,bef}});
	}
	sort(id+1, id+1+n, cmpy);
	for (int i=2; i<=n; i++) {
		int now = id[i], bef = id[i-1];
		all.psb({y[now]-y[bef], {now,bef}});
	}
	sort(all(all));
	LL ans = 0LL;
	for (auto xx : all) {
		int x = fs(xx.se.fi), y = fs(xx.se.se);
		if (x==y) continue;
		ans += (LL)xx.fi;
		p[x] = y;
	}
	printf ("%lld\n",ans);
	return 0;
}

