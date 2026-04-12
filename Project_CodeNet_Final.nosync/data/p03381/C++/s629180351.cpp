#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<int, int> P;

P p[200000];
int ans[200000];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	std::ifstream in("in");
	std::cin.rdbuf(in.rdbuf());
#endif

	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		p[i] = { a, i };
	}
	sort(p, p + N);

	for(int i = 0; i < N; i++){
		int id = p[i].second;
		if(i < N / 2) ans[id] = p[N / 2].first;
		else ans[id] = p[N / 2 - 1].first;
	}

	for(int i = 0; i < N; i++){
		cout << ans[i] << endl;
	}
}
