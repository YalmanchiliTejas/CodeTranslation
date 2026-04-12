
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>

using namespace std;

#define rep(i,n,m) for(int i=n;i<(int)(m);i++)

void sort_erase(vector<int> &num);


int dps(int start, vector<vector<bool>>& graph, vector<bool>& pass) {

	bool end=true;
	int cnt = 0;

	rep(i, 0, pass.size()) 	if (pass[i]==false)end = false;

	if (end)return 1;


	rep(i, 0, graph.size()) {

		if (graph[start][i])if (!pass[i]) {
			pass[i] = true;
			cnt += dps(i, graph, pass);
			pass[i] = false;
		}



	}

	return cnt;

}



int main() {
	
	int n, m;
	int a, b;
	
	cin >> n >> m;
	
	vector<vector<bool>>graph(n,vector<bool>(n,false));
	vector<bool>pass(n, false);
	pass[0] = true;

	rep(i, 0, m) {
		cin >> a >> b;
		graph[a-1][b-1] = true;
		graph[b-1][a-1] = true;
	}


	cout << dps(0, graph, pass) << endl;
	

	return 0;
}

void sort_erase(vector<int> &num) {
	std::sort(num.begin(), num.end());
	num.erase(std::unique(num.begin(), num.end()), num.end());
}