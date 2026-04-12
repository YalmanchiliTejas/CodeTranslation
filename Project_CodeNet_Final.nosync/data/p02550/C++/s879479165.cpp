#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
static long long INF = (1LL<<62);

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL N, X, M;
	cin >> N >> X >> M;

	vector<LL> v;
	map<LL, int> m;
	LL a = X;
	v.push_back(a);
	m[a] = 1;
	LL c = 1;
	int loop = 0;
	LL base = -1;
	for(LL c=1; c<N; c++){
		a = (a*a)%M;
		if(a == 0) break;
		if(m.count(a) == 0){
			m[a] = 1;
			v.push_back(a);
		}
		else{
			base = a;
			loop = 1;
			break;
		}
	}
	LL ans = 0;
	if(loop == 0){
		for(auto itr = m.begin(); itr != m.end(); itr++){
			LL k = itr->first;
			ans += k;
		}
		printf("%lld\n", ans);
		return 0;
	}

	LL lpos = -1;
	for(int i=0; i<v.size(); i++){
		if(v[i] == base){
			lpos = i;
			break;
		}
		else{
			ans += v[i];
		}
	}
	N -= lpos;
	LL loopsum= 0;
	for(int i=lpos; i<v.size(); i++){
		loopsum += v[i];
	}
	LL s = v.size() - lpos;
	LL q = N / s;
	LL r = N % s;
	ans += q*loopsum;
	for(int i=lpos; i<lpos+r; i++){
		ans += v[i];
	}
	printf("%lld\n", ans);
	return 0;
}