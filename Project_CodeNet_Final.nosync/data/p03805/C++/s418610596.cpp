#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef vector<set<int>> Graph;
vector<int> p = {0, 1, 2, 3, 4, 5, 6, 7};

int main() {
	int N,M,a,b,c=0;
	cin >> N >> M;
	Graph g(N);

	rep(i,M) {
		cin >> a >> b;
		--a, --b;
		g.at(a).insert(b);
		g.at(b).insert(a);
	}

	do {
		bool ok = 1;
		rep(i,N-1)
			if(!g.at(p.at(i)).count(p.at(i+1))) {
				ok = 0;
				break;
			}
		
		if(ok)
			++c;
	} while(next_permutation(p.begin()+1, p.begin()+N));

	cout << c << endl;
}