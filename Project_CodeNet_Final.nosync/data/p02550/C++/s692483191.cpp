#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll N, X, M;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> X >> M;
	ll curr = X;
	vector < ll > path; path.push_back(curr);
	set < ll > vis; vis.insert(curr);
	ll hf, result = curr, req = N - 1;
	for (int i = 2; i <= N; i ++){
		curr = (curr*curr)%M;
		if (vis.find(curr) != vis.end()){
			hf = curr;
			break;
		}
		result += curr;
		req -= 1;
		path.push_back(curr); vis.insert(curr);
	}
	ll ix = find(path.begin(), path.end(), hf) - path.begin();
	ll sz = path.size() - ix;
	ll score  = accumulate(path.begin() + ix, path.end(), 0ll);
	if (req){
		result += score * (req/sz);
		ll rem = (req % sz), iy = ix;
		while (rem--){
			result += path[iy];
			iy += 1;
		}
	}
	cout << result << "\n";		
}

// 6 1 2 6 1 2 