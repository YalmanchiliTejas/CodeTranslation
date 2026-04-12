#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> g[8];
bool b[8];

int rsearch(int depth, int cur)
{
	if(b[cur] == true){
		return 0;
	} else if(depth == N-1){
		return 1;
	} else {
		b[cur] = true;
		int res = 0;
		for(auto it=g[cur].begin(); it!=g[cur].end(); it++){
			res += rsearch(depth+1, *it);
		}
		b[cur] = false;
		return res;
	}
}

int main()
{
	cin >> N >> M;

	for(int ni=0; ni<N; ni++){
		b[ni] = false;
	}

	for(int mi=0; mi<M; mi++){
		int a, b;
		cin >> a >> b;
		g[a-1].push_back(b-1);
		g[b-1].push_back(a-1);
	}

	cout << rsearch(0, 0) << endl;

	return 0;
}
