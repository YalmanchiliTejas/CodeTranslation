#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;

int l_count(vector<int> v, vector<vector<int>> F, int s){
	s = s - 1;
	if (v.size() == 1){
		return 1;
	}
	int c = 0;
	for (auto t : F[s]){
		c += count(v.begin(), v.end(), t);
	}
	if (c == 0){
		return 0;
	}
	int ret = 0;
	vector<int> u = v;
	u.erase(remove(u.begin(), u.end(), s+1), u.end());
	for (auto t : F[s]){
		if (count(v.begin(), v.end(), t) == 1){
			ret += l_count(u, F, t);
		}
	}
	return ret;
}

int main(){
	int N, M;
	int i, j, k;
	cin >> N >> M;
	vector<int> v;
	for (i = 1; i <= N; i++){
		v.push_back(i);
	}
	vector<pair<int, int>> E;
	for (i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		E.push_back(pair<int, int>(a, b));
	}
	vector<vector<int>> F;
	for (i = 1; i <= N; i++){
		vector<int> G;
		for (j = 1; j <= N; j++){
			pair<int, int> g(i, j);
			pair<int, int> h(j, i);
			if (count(E.begin(), E.end(), g) == 1 || count(E.begin(), E.end(), h) == 1){
				G.push_back(j);
			}
		}
		F.push_back(G);
	}
	int ans = l_count(v, F, 1);

	cout << ans << endl;

}