#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	bool v[8][8] = { };
	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		v[a][b] = true;
		v[b][a] = true;
	}

	vector<int> per;
	for(int i = 1; i < N; i++)
		per.push_back(i);

	int ans = 0;
	do {
		//cout << 0 << "-" << per[0] << ":" << v[0][per[0]] << endl;
		if(! v[0][per[0]]) continue;
		bool flag = false;
		for(int i = 0; i < per.size() - 1; i++) {
			//cout << per[i] << "-" << per[i + 1] << ":" << v[per[i]][per[i + 1]] << endl;
			if(! v[per[i]][per[i + 1]]) {
				flag = true;
				break;
			}
		}
		if(flag) continue;
		ans++;
	} while(next_permutation(per.begin(), per.end()));  
	cout << ans << endl;

	return 0;
}
